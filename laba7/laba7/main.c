#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include "my_lab.h"

int main() {
    setlocale("");
    char input[50];

    printf("������� ����� (����������, ������������ ��� �����������������): ");
    scanf("%49s", input);

    long number = string_to_long(input);
    printf("���������: %ld\n", number);

    return 0;
}
