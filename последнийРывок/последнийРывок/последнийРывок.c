#include <stdio.h>

int main() {
    int arr[100];
    int count = 0;

    // ��������� ������ ���������� ������� �� 0 �� 50 ��� �������
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 51; // ���������� ����� �� 0 �� 50
    }

    // ������� ���������, ������� 18
    for (int i = 0; i < 100; i++) {
        if (arr[i] < 18) {
            count++;
        }
    }

    printf("���������� ��������� ������ 18: %d\n", count);

    return 0;
}
