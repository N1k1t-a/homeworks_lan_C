#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_lab.h"

long string_to_long(const char* str) {
    if (str == NULL) {
        return 0; // ���������� 0 ��� ������
    }

    // ���������� ������� ���������
    int base = 10; // �� ��������� ����������
    if (str[0] == '0') {
        if (tolower(str[1]) == 'x') {
            base = 16; // ����������������� (0x...)
            str += 2;  // ���������� "0x"
        }
        else {
            base = 8;  // ������������ (0...)
            str += 1;  // ���������� "0"
        }
    }

    char* endptr;
    long result = strtol(str, &endptr, base);

    if (*endptr != '\0') {
        printf("������: ������������ ����!\n");
        return 0; // ���������� 0, ���� ���� �� �������� ������
    }

    return result;
}
