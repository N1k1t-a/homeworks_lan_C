#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_lab.h"

long string_to_long(const char* str) {
    if (str == NULL) {
        return 0; // Возвращаем 0 при ошибке
    }

    // Определяем систему счисления
    int base = 10; // По умолчанию десятичная
    if (str[0] == '0') {
        if (tolower(str[1]) == 'x') {
            base = 16; // Шестнадцатеричная (0x...)
            str += 2;  // Пропускаем "0x"
        }
        else {
            base = 8;  // Восьмеричная (0...)
            str += 1;  // Пропускаем "0"
        }
    }

    char* endptr;
    long result = strtol(str, &endptr, base);

    if (*endptr != '\0') {
        printf("Ошибка: Некорректный ввод!\n");
        return 0; // Возвращаем 0, если ввод не является числом
    }

    return result;
}
