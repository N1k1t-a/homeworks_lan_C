#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include "my_lab.h"

int main() {
    setlocale("");
    char input[50];

    printf("Введите число (десятичное, восьмеричное или шестнадцатеричное): ");
    scanf("%49s", input);

    long number = string_to_long(input);
    printf("Результат: %ld\n", number);

    return 0;
}
