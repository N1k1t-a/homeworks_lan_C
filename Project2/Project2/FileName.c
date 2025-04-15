#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define STR_SIZE 128 

int my_strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    if ((*s1 == ':') || (*s1 == '.') || (*s1 == ';') || (*s1 == '!') || (*s1 == '?') || (*s1 == ',')) {
        s1++;
    }
    return *s1 - *s2;
}

char* my_itoa(int num, char punctuation) {
    char* buffer = (char*)malloc(4 * sizeof(char)); 

    int i = 0;
    if (num == 0) {
        buffer[i++] = '0';
    }
    else if (num == 10) {
        buffer[i++] = '1';
        buffer[i++] = '0';
    }
    else {
        buffer[i++] = (num % 10) + '0';
    }

    if (punctuation) {
        buffer[i++] = punctuation; 
    }

    buffer[i] = '\0';
    return buffer;
}


char* replace_word(const char* word) {
    char* numbers[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };

    char clean_word[STR_SIZE];
    char punctuation = '\0';
    int i = 0;

    while (word[i] && word[i] != ':' && word[i] != '.' && word[i] != ';' && word[i] != '!' && word[i] != '?' && word[i] != ',') {
        clean_word[i] = word[i];
        i++;
    }

    if (word[i]) { 
        punctuation = word[i];
    }

    clean_word[i] = '\0';

    for (int j = 0; j < 11; j++) {
        if (my_strcmp(clean_word, numbers[j]) == 0) {
            return my_itoa(j, punctuation);
        }
    }

    char* copy = malloc((STR_SIZE) * sizeof(char));
    i = 0;
    while (word[i]) {
        copy[i] = word[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}



char** return_str(const char* input, int* word_count) {
    *word_count = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if ((i == 0 || input[i - 1] == ' ') && input[i] != ' ') {
            (*word_count)++;
        }
    }

    char** words = malloc((*word_count) * sizeof(char*));

    char word[STR_SIZE];
    int word_index = 0;
    int i = 0;

    while (*input) {
        if (*input != ' ' && *input != '\n') {
            word[i++] = *input;
        }
        else if (i > 0) {
            word[i] = '\0';
            words[word_index++] = replace_word(word);
            i = 0;
        }
        input++;
    }

    if (i > 0) {
        word[i] = '\0';
        words[word_index++] = replace_word(word);
    }

    return words;
}

int main() {
    setlocale(LC_ALL, "Rus");

    char input[STR_SIZE];
    printf("Введите строку: ");
    fgets(input, STR_SIZE, stdin);

    int word_count = 0;
    char** words = return_str(input, &word_count);

    printf("Измененная строка: ");
    for (int i = 0; i < word_count; i++) {
        printf("%s ", words[i]);
        free(words[i]);
    }
    free(words);

    printf("\n");

    char test_inputs[3][STR_SIZE] = {
        "one two three four five six seven eight nine ten 1",
        "oneds, two, three",
        "I woke up at seven a.m. ",
    };

    for (int t = 0; t < 3; t++) {
        printf("\nТестовая строка: %s\n", test_inputs[t]);

        int word_count = 0;
        char** words = return_str(test_inputs[t], &word_count);

        printf("Измененная строка: ");
        for (int i = 0; i < word_count; i++) {
            printf("%s ", words[i]);
            free(words[i]); 
        }
        free(words); 

        printf("\n");
    }    
    return 0;
}