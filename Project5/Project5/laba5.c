#include <stdio.h>
#include <string.h>
#include <locale.h>

#define STR_SIZE 128  
#define MAX_WORDS 50  


int hasUniqueLetters(const char* word) {
    for (int i = 0; word[i] != '\0'; i++) {
        for (int j = i + 1; word[j] != '\0'; j++) {
            if (word[i] == word[j]) {
                return 0;
            }
        }
    }
    return 1;
}


int hasUniqueLettersInString(const char* word, char words[][STR_SIZE], int wordCount) {
    for (int i = 0; word[i] != '\0'; i++) {
        for (int j = 0; j < wordCount; j++) {

            int k = 0;
            while (words[j][k] != '\0' && word[k] == words[j][k]) {
                k++;
            }
            if (words[j][k] == '\0' && word[k] == '\0') {
                continue; 
            }

            for (int k = 0; words[j][k] != '\0'; k++) {
                if (word[i] == words[j][k]) {
                    return 0;  
                }
            }
        }
    }
    return 1;
}


int strConvert(const char* s, char parts[][STR_SIZE]) {
    int r = 0;
    while (*s) {
        if (*s != ' ') {
            char* ptr = parts[r++];
            do {
                *(ptr++) = *(s++);
            } while (*s && *s != ' ');
            *ptr = '\0';
        }
        else {
            ++s;
        }
    }
    return r;
}

int main() {
    setlocale(LC_ALL, "");
    char testInputs[3][STR_SIZE] = {
        "дом дерево трава лун",
        "€блоко банан виноград",
        "ааа бб ввв гд",
    };

    for (int t = 0; t < 3; t++) {
        char words[MAX_WORDS][STR_SIZE];
        printf("\n“естова€ строка: \"%s\"\n", testInputs[t]);

        int wordCount = strConvert(testInputs[t], words);

        printf("—лова без повтор€ющихс€ букв:\n");
        for (int i = 0; i < wordCount; i++) {
            if (hasUniqueLetters(words[i]) && hasUniqueLettersInString(words[i], words, wordCount)) {
                printf("%s\n", words[i]);
            }
        }
    }

    return 0;
}
