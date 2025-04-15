#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STR_LEN 1000
#define MAX_WORDS 100
#define MAX_WORD_LEN 100

// Функция для вычисления длины строки
int str_length(const char* s) {
    int len = 0;
    while (*s++) {
        len++;
    }
    return len;
}

// Функция для копирования строки
int str_copy(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return 0;
}

// Функция для считывания строки
int str_input(char* str, int max_len) {
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF && i < max_len - 1) {
        str[i++] = c;
    }
    str[i] = '\0';
    return 0;
}

// Функция для разбиения строки на слова
int split_into_words(const char* str, char words[][MAX_WORD_LEN]) {
    int word_count = 0;
    int i = 0, j = 0;

    while (str[i] != '\0') {
        // Пропуск пробелов
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            i++;
        }
        if (str[i] == '\0') {
            break;
        }

        // Копирование символов слова
        j = 0;
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0' && j < MAX_WORD_LEN - 1) {
            words[word_count][j++] = str[i++];
        }
        words[word_count][j] = '\0'; // Завершение строки
        word_count++;

        // Проверка на переполнение массива слов
        if (word_count >= MAX_WORDS) {
            printf("Превышено максимально допустимое число слов!\n");
            return word_count;
        }
    }

    return word_count;
}

// Функция для нахождения индекса самого длинного слова
int find_longest_word_index(char words[][MAX_WORD_LEN], int word_count, int used[]) {
    int max_len = -1;
    int index = -1;

    for (int i = 0; i < word_count; i++) {
        if (!used[i]) { // Пропуск уже использованных слов
            int len = str_length(words[i]);
            if (len > max_len) {
                max_len = len;
                index = i;
            }
        }
    }

    return index;
}

int main() {
    char str[MAX_STR_LEN];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int used[MAX_WORDS] = { 0 };
    int word_count;

    printf("Input string: ");
    str_input(str, MAX_STR_LEN); // Считывание строки без использования fgets

    // Разделение строки на слова
    word_count = split_into_words(str, words);
    if (word_count == 0) {
        printf("Нет слов для обработки.\n");
        return 0;
    }

    // Вывод слов в порядке убывания длины
    printf("Words in descending order of length:\n");
    for (int i = 0; i < word_count; i++) {
        int longest_index = find_longest_word_index(words, word_count, used);
        if (longest_index != -1) {
            printf("%s\n", words[longest_index]);
            used[longest_index] = 1;
        }
    }

    return 0;
}
