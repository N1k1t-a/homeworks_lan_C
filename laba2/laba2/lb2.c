#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, k; // �������� �� ����� � �������� �
    printf("type integer: ");
    scanf("%d", &n);

    printf("type interger two: ");
    scanf("%d", &k);

    while (n % k == 0) {
        n = n / k;
    }

    if (n == 1) {
        printf("true");
    }
    else {
        printf("false");
    }

    return 0;
}
