#include <stdio.h>

int main() {
    int arr[100];
    int count = 0;

    // Заполняем массив случайными числами от 0 до 50 для примера
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 51; // Генерируем числа от 0 до 50
    }

    // Подсчёт элементов, меньших 18
    for (int i = 0; i < 100; i++) {
        if (arr[i] < 18) {
            count++;
        }
    }

    printf("Количество элементов меньше 18: %d\n", count);

    return 0;
}
