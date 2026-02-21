#define _CRT_SECURE_NO_WARNINGS
#include "File3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ShowData(const DB* db) {
    if (!db->count) { puts("Нет записей."); return; }
    printf(" %-3s | %-20s | %-20s | %-6s | %-8s | %-10s\n",
        "No", "Преподаватель", "Дисциплина", "Курс", "Семестр", "Аудитория");
    puts("-----+----------------------+----------------------+--------+----------+-----------");
    for (unsigned i = 0; i < db->count; ++i) {
        printf(" %-3u | %-20s | %-20s | %-6d | %-8d | %-10s\n",
            i + 1,
            db->arr[i].teacher,
            db->arr[i].discipline,
            db->arr[i].course,
            db->arr[i].semester,
            db->arr[i].auditorium);
    }
}

void AddRecord(DB* db) {
    if (db->count >= db->capacity) {
        unsigned newcap = db->capacity ? db->capacity * 2 : 10;
        Record* tmp = realloc(db->arr, newcap * sizeof(Record));
        if (!tmp) { puts("Не удалось выделить память."); return; }
        db->arr = tmp;
        db->capacity = newcap;
    }
    Record* r = &db->arr[db->count];
    getchar();
    printf("Преподаватель: "); fgets(r->teacher, sizeof r->teacher, stdin);
    r->teacher[strcspn(r->teacher, "\n")] = '\0';
    printf("Дисциплина:   "); fgets(r->discipline, sizeof r->discipline, stdin);
    r->discipline[strcspn(r->discipline, "\n")] = '\0';
    printf("Курс:         "); scanf("%d", &r->course);
    printf("Семестр:      "); scanf("%d", &r->semester);
    getchar();
    printf("Аудитория:    "); fgets(r->auditorium, sizeof r->auditorium, stdin);
    r->auditorium[strcspn(r->auditorium, "\n")] = '\0';
    db->count++;
    puts("Запись добавлена.");
}


void EditRecord(DB* db) {
    unsigned idx;
    printf("Номер для редактирования: ");
    if (scanf("%u", &idx) != 1 || idx < 1 || idx > db->count) {
        puts("Неверный номер.");
        while (getchar() != '\n');
        return;
    }
    idx--;  // приводим к 0-based
    // очищаем остаток консольного ввода перед fgets
    getchar();

    Record* r = &db->arr[idx];
    int choice;
    do {

        printf("\nТекущая запись #%u:\n", idx + 1);
        printf("1) Преподаватель: %s\n", r->teacher);
        printf("2) Дисциплина:    %s\n", r->discipline);
        printf("3) Курс:          %d\n", r->course);
        printf("4) Семестр:       %d\n", r->semester);
        printf("5) Аудитория:     %s\n", r->auditorium);
        printf("0) Сохранить и выйти\n");
        printf("Выберите поле для редактирования (0–5): ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }
        getchar();

        switch (choice) {
        case 1: 
            printf("Новый преподаватель: ");
            fgets(r->teacher, sizeof r->teacher, stdin);
            r->teacher[strcspn(r->teacher, "\n")] = '\0';
            break;
        case 2:  // редактируем discipline
            printf("Новая дисциплина:    ");
            fgets(r->discipline, sizeof r->discipline, stdin);
            r->discipline[strcspn(r->discipline, "\n")] = '\0';
            break;
        case 3: 
            printf("Новый курс:          ");
            scanf("%d", &r->course);
            while (getchar() != '\n');
            break;
        case 4:
            printf("Новый семестр:       ");
            scanf("%d", &r->semester);
            while (getchar() != '\n');
            break;
        case 5:  
            printf("Новая аудитория:     ");
            fgets(r->auditorium, sizeof r->auditorium, stdin);
            r->auditorium[strcspn(r->auditorium, "\n")] = '\0';
            break;
        case 0:
            break;
        default:
            puts("Неверный выбор. Попробуйте снова.");
        }
    } while (choice != 0);

    puts("Запись отредактирована.");
}

void DeleteRecord(DB* db) {
    unsigned idx;
    printf("Номер для удаления: ");
    if (scanf("%u", &idx) != 1 || idx<1 || idx>db->count) { puts("Неверный номер."); while (getchar() != '\n'); return; }
    for (unsigned i = idx - 1; i < db->count - 1; ++i) db->arr[i] = db->arr[i + 1];
    db->count--;
    puts("Запись удалена.");
}

static int cmpAsc(const void* a, const void* b) {
    return strcmp(((Record*)a)->discipline, ((Record*)b)->discipline);
}
static int cmpDesc(const void* a, const void* b) {
    return strcmp(((Record*)b)->discipline, ((Record*)a)->discipline);
}

void SortData(DB* db) {
    int asc;
    printf("1-возрастание, 0-убывание: ");
    scanf("%d", &asc);
    if (db->count > 1) qsort(db->arr, db->count, sizeof(Record), asc ? cmpAsc : cmpDesc);
    puts("Сортировка завершена.");
}

void FindRecord(const DB* db) {
    char key[64];
    getchar();
    printf("Введите часть названия дисциплины: ");
    fgets(key, sizeof key, stdin);
    key[strcspn(key, "\n")] = '\0';
    unsigned found = 0;
    for (unsigned i = 0; i < db->count; ++i) {
        if (strstr(db->arr[i].discipline, key)) {
            if (!found) ShowData(db);
            printf("  -> %u | %s | %s\n", i + 1, db->arr[i].teacher, db->arr[i].discipline);
            found++;
        }
    }
    if (!found) puts("Совпадений не найдено.");
}

void Stats(const DB* db) {
    if (!db->count) { puts("Нет данных для статистики."); return; }
    double sum = 0; int mx = db->arr[0].semester;
    for (unsigned i = 0; i < db->count; ++i) {
        sum += db->arr[i].course;
        if (db->arr[i].semester > mx) mx = db->arr[i].semester;
    }
    printf("Средний курс: %.2f\nМаксимальный семестр: %d\n", sum / db->count, mx);
}
