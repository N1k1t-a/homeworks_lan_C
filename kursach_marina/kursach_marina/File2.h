// File2.h
#ifndef FILE2_H
#define FILE2_H

#include "File1.h"

// Функции чтения/сохранения базы в CSV или TXT
void ReadDatabase(Record** data, unsigned* count, unsigned* capacity, const char* base);
void SaveDatabase(const Record* data, unsigned count, const char* base);

#endif // FILE2_H
#pragma once
