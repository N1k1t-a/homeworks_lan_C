#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <locale.h>

#define MAX_CHILDREN 100

typedef struct Node {
    char* name;
    int is_file;
    struct Node* children[MAX_CHILDREN];
    int child_count;
} Node;

Node* create_node(const char* name, int is_file) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->name = _strdup(name);
    node->is_file = is_file;
    node->child_count = 0;
    return node;
}

Node* find_or_add_child(Node* parent, const char* name, int is_file) {
    for (int i = 0; i < parent->child_count; i++) {
        if (strcmp(parent->children[i]->name, name) == 0) {
            return parent->children[i];
        }
    }
    Node* child = create_node(name, is_file);
    parent->children[parent->child_count++] = child;
    return child;
}

void insert_path(Node* root, const char* path) {
    char buffer[1024];
    strcpy(buffer, path);

    char* token = strtok(buffer, "\\/");
    Node* current = root;

    while (token != NULL) {
        char* next = strtok(NULL, "\\/");
        int is_file = (next == NULL && strchr(token, '.') != NULL);
        current = find_or_add_child(current, token, is_file);
        token = next;
    }
}

void print_tree(Node* node, int depth) {
    for (int i = 0; i < depth; i++) printf("    ");
    if (depth > 0) printf("|--- ");
    printf("%s\n", node->name);
    for (int i = 0; i < node->child_count; i++) {
        print_tree(node->children[i], depth + 1);
    }
}

void free_tree(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->name);
    free(node);
}

int main() {
    setlocale(LC_ALL, "Russian");
    FILE* file = fopen("C:/Users/aboob/source/repos/laba12/laba12/x64/Debug/comments.txt", "r");
    if (!file) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }


    Node* roots[26] = { 0 };
    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') line[len - 1] = '\0';
        if (strlen(line) == 0) continue;


        char disk_letter = toupper(line[0]);
        int disk_index = disk_letter - 'A';

        if (roots[disk_index] == NULL) {
            char disk_name[3] = { disk_letter, ':', '\0' };
            roots[disk_index] = create_node(disk_name, 0);
        }

        insert_path(roots[disk_index], line + 3); 
    }

    fclose(file);

    for (int i = 0; i < 26; i++) {
        if (roots[i]) {
            print_tree(roots[i], 0);
            free_tree(roots[i]);
        }
    }

    return 0;
}
