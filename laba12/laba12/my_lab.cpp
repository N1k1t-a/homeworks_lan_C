#define _CRT_SECURE_NO_WARNINGS 
#include "my_lab.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void pathsplit(char* path, char* split[]) {
    char* colon = strchr(path, ':');
    if (colon) {
        size_t len = colon - path;
        split[0] = (char*)malloc(len + 1);
        strncpy(split[0], path, len);
        split[0][len] = '\0';
    }
    else {
        split[0] = (char*)malloc(1);
        split[0][0] = '\0';
    }

    char* last_slash = strrchr(path, '\\');
    char* last_dot = strrchr(path, '.');

    if (last_slash && colon && last_slash > colon) {
        size_t len = last_slash - (colon + 1);
        split[1] = (char*)malloc(len + 1);
        strncpy(split[1], colon + 1, len);
        split[1][len] = '\0';
    }
    else {
        split[1] = (char*)malloc(1);
        split[1][0] = '\0';
    }

    if (last_slash && last_dot && last_dot > last_slash) {
        size_t len = last_dot - (last_slash + 1);
        split[2] = (char*)malloc(len + 1);
        strncpy(split[2], last_slash + 1, len);
        split[2][len] = '\0';
    }
    else {
        split[2] = (char*)malloc(1);
        split[2][0] = '\0';
    }

    if (last_dot) {
        split[3] = (char*)malloc(strlen(last_dot));
        strcpy(split[3], last_dot + 1);
    }
    else {
        split[3] = (char*)malloc(1);
        split[3][0] = '\0';
    }
}

char* normalize_path(const char* path) {
    char* result = (char*)malloc(strlen(path) + 1);
    strcpy(result, path);
    for (int i = 0; result[i] != '\0'; i++) {
        if (result[i] == '\\') {
            result[i] = '/';
        }
    }
    return result;
}

void print_tree(const char* disk, const char* folder_path, const char* filename, const char* ext) {
    printf(" %s\n", disk);

    char* path_copy = (char*)malloc(strlen(folder_path) + 1);
    strcpy(path_copy, folder_path);

    char* token = strtok(path_copy, "/");
    int depth = 0;
    while (token != NULL) {
        for (int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("|--- %s\n", token);
        depth++;
        token = strtok(NULL, "/");
    }

    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("|---%s.%s\n", filename, ext);

    free(path_copy);
}
