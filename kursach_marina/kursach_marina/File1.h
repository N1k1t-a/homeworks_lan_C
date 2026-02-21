// File1.h
#ifndef SCHEDULE_DB_H
#define SCHEDULE_DB_H

// Структура записи расписания занятий
typedef struct {
    char teacher[64];       // преподаватель
    char discipline[64];    // дисциплина
    int course;             // курс
    int semester;           // семестр
    char auditorium[32];    // аудитория
} Record;

// Команды меню
typedef enum {
    CMD_EXIT = -1,
    CMD_NONE,
    CMD_READ,
    CMD_SHOW,
    CMD_ADD,
    CMD_EDIT,
    CMD_DELETE,
    CMD_SORT,
    CMD_FIND,
    CMD_STATS,
    CMD_SAVE
} Command;

#endif // SCHEDULE_DB_H
#pragma once
