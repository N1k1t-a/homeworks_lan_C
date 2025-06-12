#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "File1.h"
#include "File2.h"
#include "File3.h"


static Command MenuMain(void) {
    int opt;
    do {
        system("cls");
        puts("=== Меню расписания занятий ===");
        puts("1 - Загрузить базу");
        puts("2 - Показать записи");
        puts("3 - Добавить запись");
        puts("4 - Редактировать запись");
        puts("5 - Удалить запись");
        puts("6 - Сортировать записи");
        puts("7 - Найти по дисциплине");
        puts("8 - Статистика");
        puts("9 - Сохранить базу");
        puts("0 - Выход");
        printf("Выберите действие: ");
        scanf("%d", &opt);
    } while (opt < 0 || opt > 9);

    switch (opt) {
    case 1: return CMD_READ;
    case 2: return CMD_SHOW;
    case 3: return CMD_ADD;
    case 4: return CMD_EDIT;
    case 5: return CMD_DELETE;
    case 6: return CMD_SORT;
    case 7: return CMD_FIND;
    case 8: return CMD_STATS;
    case 9: return CMD_SAVE;
    case 0: return CMD_EXIT;
    default: return CMD_NONE;
    }
}

int main(void) {
    system("chcp 1251");
    DB db = { .arr = NULL, .count = 0, .capacity = 0 };
    char baseName[128];
    Command cmd;

    do {
        cmd = MenuMain();
        switch (cmd) {
        case CMD_READ:
            printf("Введите имя файла (без расширения): ");
            scanf("%127s", baseName);
            ReadDatabase(&db.arr, &db.count, &db.capacity, baseName);
            break;

        case CMD_SHOW:   ShowData(&db); break;
        case CMD_ADD:    AddRecord(&db); break;
        case CMD_EDIT:   EditRecord(&db); break;
        case CMD_DELETE: DeleteRecord(&db); break;
        case CMD_SORT:   SortData(&db); break;
        case CMD_FIND:   FindRecord(&db); break;
        case CMD_STATS:  Stats(&db); break;

        case CMD_SAVE:
            printf("Введите имя для сохранения (без расширения): ");
            scanf("%127s", baseName);
            SaveDatabase(db.arr, db.count, baseName);
            break;

        case CMD_EXIT: break;
        default: break;
        }
        if (cmd != CMD_EXIT) {
            printf("\nНажмите Enter для продолжения...");
            getchar(); getchar();
        }
    } while (cmd != CMD_EXIT);

    free(db.arr);
    puts("Выход из программы.");
    return 0;
}
