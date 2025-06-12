#define _CRT_SECURE_NO_WARNINGS
#include "File2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Проверка существования файла
static int file_exists(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) return 0;
    fclose(f);
    return 1;
}

// Загрузка из CSV (разделитель ',')
static void ReadCSV(Record** data, unsigned* count, unsigned* capacity, const char* base) {
    char path[256];
    snprintf(path, sizeof(path), "%s.csv", base);
    FILE* f = fopen(path, "r");
    if (!f) { perror("Ошибка открытия CSV"); return; }

    char line[256]; unsigned lines = 0;
    while (fgets(line, sizeof(line), f)) if (strchr(line, ',')) lines++;
    rewind(f);

    *capacity = lines ? lines : 10;
    *data = malloc(*capacity * sizeof(Record));
    *count = 0;

    while (fgets(line, sizeof(line), f)) {
        char* tok = strtok(line, ",");
        if (!tok) continue;
        Record rec;
        strncpy(rec.teacher, tok, sizeof(rec.teacher)); rec.teacher[sizeof(rec.teacher) - 1] = '\0';
        tok = strtok(NULL, ","); strncpy(rec.discipline, tok ? tok : "", sizeof(rec.discipline)); rec.discipline[sizeof(rec.discipline) - 1] = '\0';
        tok = strtok(NULL, ","); rec.course = tok ? atoi(tok) : 0;
        tok = strtok(NULL, ","); rec.semester = tok ? atoi(tok) : 0;
        tok = strtok(NULL, ",\n"); strncpy(rec.auditorium, tok ? tok : "", sizeof(rec.auditorium)); rec.auditorium[sizeof(rec.auditorium) - 1] = '\0';
        (*data)[(*count)++] = rec;
    }
    fclose(f);
    printf("Загружено из CSV: %u записей\n", *count);
}

// Загрузка из TXT (разделитель ';')
static void ReadTXT(Record** data, unsigned* count, unsigned* capacity, const char* base) {
    char path[256];
    snprintf(path, sizeof(path), "%s.txt", base);
    FILE* f = fopen(path, "r");
    if (!f) { perror("Ошибка открытия TXT"); return; }

    char line[256]; unsigned lines = 0;
    while (fgets(line, sizeof(line), f)) if (strchr(line, ';')) lines++;
    rewind(f);

    *capacity = lines ? lines : 10;
    *data = malloc(*capacity * sizeof(Record));
    *count = 0;

    while (fgets(line, sizeof(line), f)) {
        char* tok = strtok(line, ";");
        if (!tok) continue;
        Record rec;
        strncpy(rec.teacher, tok, sizeof(rec.teacher)); rec.teacher[sizeof(rec.teacher) - 1] = '\0';
        tok = strtok(NULL, ";"); strncpy(rec.discipline, tok ? tok : "", sizeof(rec.discipline)); rec.discipline[sizeof(rec.discipline) - 1] = '\0';
        tok = strtok(NULL, ";"); rec.course = tok ? atoi(tok) : 0;
        tok = strtok(NULL, ";"); rec.semester = tok ? atoi(tok) : 0;
        tok = strtok(NULL, ";\n"); strncpy(rec.auditorium, tok ? tok : "", sizeof(rec.auditorium)); rec.auditorium[sizeof(rec.auditorium) - 1] = '\0';
        (*data)[(*count)++] = rec;
    }
    fclose(f);
    printf("Загружено из TXT: %u записей\n", *count);
}

// Выбор формата и загрузка
void ReadDatabase(Record** data, unsigned* count, unsigned* capacity, const char* base) {
    char csv_path[256], txt_path[256];
    snprintf(csv_path, sizeof(csv_path), "%s.csv", base);
    snprintf(txt_path, sizeof(txt_path), "%s.txt", base);
    int has_csv = file_exists(csv_path);
    int has_txt = file_exists(txt_path);

    if (has_csv && has_txt) {
        int opt;
        printf("Найдены %s.csv и %s.txt. Выберите (1-CSV, 2-TXT): ", base, base);
        scanf("%d", &opt); while (getchar() != '\n');
        if (opt == 1) ReadCSV(data, count, capacity, base);
        else           ReadTXT(data, count, capacity, base);
    }
    else if (has_csv) {
        ReadCSV(data, count, capacity, base);
    }
    else if (has_txt) {
        ReadTXT(data, count, capacity, base);
    }
    else {
        printf("Ни %s.csv, ни %s.txt не найдены.\n", base, base);
        *data = NULL; *count = *capacity = 0;
    }
}

// Сохранение в CSV
static void SaveCSV(const Record* data, unsigned count, const char* base) {
    char path[256];
    snprintf(path, sizeof(path), "%s.csv", base);
    FILE* f = fopen(path, "w");
    if (!f) { perror("Ошибка создания CSV"); return; }
    for (unsigned i = 0; i < count; ++i) {
        fprintf(f, "%s,%s,%d,%d,%s\n",
            data[i].teacher,
            data[i].discipline,
            data[i].course,
            data[i].semester,
            data[i].auditorium);
    }
    fclose(f);
    printf("Сохранено в CSV: %u записей\n", count);
}

// Сохранение в TXT
static void SaveTXT(const Record* data, unsigned count, const char* base) {
    char path[256];
    snprintf(path, sizeof(path), "%s.txt", base);
    FILE* f = fopen(path, "w");
    if (!f) { perror("Ошибка создания TXT"); return; }
    for (unsigned i = 0; i < count; ++i) {
        fprintf(f, "%s;%s;%d;%d;%s\n",
            data[i].teacher,
            data[i].discipline,
            data[i].course,
            data[i].semester,
            data[i].auditorium);
    }
    fclose(f);
    printf("Сохранено в TXT: %u записей\n", count);
}

// Выбор формата и сохранение
void SaveDatabase(const Record* data, unsigned count, const char* base) {
    int opt;
    printf("Выберите формат сохранения (1-CSV, 2-TXT): ");
    scanf("%d", &opt); while (getchar() != '\n');
    if (opt == 1) SaveCSV(data, count, base);
    else           SaveTXT(data, count, base);
}
