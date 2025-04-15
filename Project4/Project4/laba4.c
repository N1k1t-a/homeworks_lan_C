#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>


int finding_nums(float str_num[], int size, float result[]) {
    float min_fractional = 0.0;
    int found = 0;
    int count = 0; 

    for (int i = 0; i < size; i++) {
        float fractional_part = str_num[i] - (int)str_num[i];

        if (fractional_part > 0) {
            if (found == 0 || fractional_part < min_fractional) {
                min_fractional = fractional_part;
                found = 1;
                count = 0;
                result[count++] = str_num[i]; 
            }
            else if (fractional_part == min_fractional) {
                result[count++] = str_num[i]; 
            }
        }
    }

    return count;
}


int main() {
    setlocale(LC_ALL, "");

    float numbers[100];
    int i = 0;
    float result[100];

    printf("введите числа: \n");
    while (i < 100 && scanf("%f", &numbers[i]) == 1) {
        i++;
    }

    int answer = finding_nums(numbers, i, result);

    if (answer > 0) {
        printf("Числа с минимальной положительной дробной частью:\n");
        for (int j = 0; j < answer; j++) {
            printf("%.2f\n", result[j]);
        }
    }
    else {
        printf("Положительных дробных частей нет.\n");
    }


    float test1[] = { 3.14, 2.71, 1.618, 4.5 };
    float test2[] = { -1.5, 2.3, 3.7, -4.6, 5.8 };
    float test3[] = { 0.5, 1.5, 2.5, 3.5 };

    printf("\nТест 1:\n");
    answer = finding_nums(test1, 5, result);
    for (int j = 0; j < answer; j++) {
        printf("%.2f\n", result[j]);
    }

    printf("\nТест 2:\n");
    answer = finding_nums(test2, 6, result);
    for (int j = 0; j < answer; j++) {
        printf("%.2f\n", result[j]);
    }

    printf("\nТест 3:\n");
    answer = finding_nums(test3, 4, result);
    for (int j = 0; j < answer; j++) {
        printf("%.2f\n", result[j]);
    }

    return 0;

}

