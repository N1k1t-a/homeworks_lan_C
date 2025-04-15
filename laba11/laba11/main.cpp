#define _CRT_SECURE_NO_WARNINGS
#include "my_lab.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "RU");

    const char* input_filename = "C:\\Users\\aboob\\source\\repos\\laba11\\laba11\\x64\\Debug\\example.c";
    const char* output_filename = "C:\\Users\\aboob\\source\\repos\\laba11\\laba11\\x64\\Debug\\comments.txt";

    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("�� ������� ������� ������� ����.\n");
        return 1;
    }

    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("�� ������� ������� ���� ��� ������ ������������.\n");
        fclose(input_file);
        return 1;
    }

    count_operations(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("����������� ��������\n");
    return 0;
}
