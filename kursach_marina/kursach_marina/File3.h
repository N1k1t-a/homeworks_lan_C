// File3.h
#ifndef FILE3_H
#define FILE3_H

#include "File1.h"

//  онтейнер дл€ динамического массива записей
typedef struct {
    Record* arr;
    unsigned count;
    unsigned capacity;
} DB;

void ShowData(const DB* db);
void AddRecord(DB* db);
void EditRecord(DB* db);
void DeleteRecord(DB* db);
void SortData(DB* db);
void FindRecord(const DB* db);
void Stats(const DB* db);

#endif // FILE3_H
#pragma once
