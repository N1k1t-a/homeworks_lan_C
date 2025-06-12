#include "ui.hpp"
#include "file_io.hpp"
#include "db_ops.hpp"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void run_ui(vector<Univer>& db) {
    setlocale(LC_ALL, "Russian");
    bool running = true;
    while (running) {
        cout << "\n=== Меню ===\n"
            << "1. Загрузить БД из файла\n"
            << "2. Просмотр записей\n"
            << "3. Добавить запись\n"
            << "4. Редактировать запись\n"
            << "5. Удалить запись\n"
            << "6. Сортировать по курсу (возр.)\n"
            << "7. Сортировать по курсу (уб.)\n"
            << "8. Сортировать по семестру (возр.)\n"
            << "9. Сортировать по семестру (уб.)\n"
            << "10. Поиск по дисциплине\n"
            << "11. Статистика\n"
            << "12. Сохранить БД в файл\n"
            << "0. Выход\n"
            << "Выберите действие: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            string fn;
            cout << "Файл для чтения: ";
            getline(cin, fn);
            if (load_db(fn, db))
                cout << "Загружено " << db.size() << " записей.\n";
            else
                cout << "Ошибка чтения.\n";
            break;
        }
        case 2:
            view_db(db);
            break;
        case 3: {
            Univer r;
            cout << "Преподаватель: ";   getline(cin, r.teacher);
            cout << "Дисциплина: ";      getline(cin, r.subject);
            cout << "Курс: ";            cin >> r.course;
            cout << "Семестр: ";        cin >> r.semester;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Аудитория: ";       getline(cin, r.auditorium);
            db.push_back(move(r));
            cout << "Добавлено.\n";
            break;
        }
        case 4: {
            if (db.empty()) { cout << "Пусто.\n"; break; }
            cout << "Номер записи (1-" << db.size() << "): ";
            size_t idx; cin >> idx;
            if (idx < 1 || idx > db.size()) {
                cout << "Неверный номер.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            --idx;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            auto& r = db[idx];
            cout << "Преподаватель (" << r.teacher << "): ";
            getline(cin, r.teacher);
            cout << "Дисциплина (" << r.subject << "): ";
            getline(cin, r.subject);
            cout << "Курс (" << r.course << "): ";
            cin >> r.course;
            cout << "Семестр (" << r.semester << "): ";
            cin >> r.semester;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Аудитория (" << r.auditorium << "): ";
            getline(cin, r.auditorium);
            cout << "Обновлено.\n";
            break;
        }
        case 5: {
            if (db.empty()) { cout << "Пусто.\n"; break; }
            cout << "Номер для удаления (1-" << db.size() << "): ";
            size_t idx; cin >> idx;
            if (idx < 1 || idx > db.size()) {
                cout << "Неверный номер.\n";
            }
            else {
                db.erase(db.begin() + (idx - 1));
                cout << "Удалено.\n";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        case 6:
            sort_by_course(db, true);
            cout << "Сортировка по курсу (возр.) выполнена.\n";
            break;
        case 7:
            sort_by_course(db, false);
            cout << "Сортировка по курсу (уб.) выполнена.\n";
            break;
        case 8:
            sort_by_semester(db, true);
            cout << "Сортировка по семестру (возр.) выполнена.\n";
            break;
        case 9:
            sort_by_semester(db, false);
            cout << "Сортировка по семестру (уб.) выполнена.\n";
            break;
        case 10: {
            string q;
            cout << "Запрос: "; getline(cin, q);
            auto res = search_by_subject(db, q);
            view_db(res);
            break;
        }
        case 11: {
            cout << "Средний курс: " << average_course(db)
                << ", средний семестр: " << average_semester(db) << "\n";
            if (!db.empty()) {
                cout << "Max курс:\n"; view_db({ max_course_record(db) });
                cout << "Min курс:\n"; view_db({ min_course_record(db) });
                cout << "Max семестр:\n"; view_db({ max_semester_record(db) });
                cout << "Min семестр:\n"; view_db({ min_semester_record(db) });
            }
            break;
        }
        case 12: {
            string fn;
            cout << "Файл для записи: "; getline(cin, fn);
            if (save_db(fn, db))
                cout << "Сохранено.\n";
            else
                cout << "Ошибка записи.\n";
            break;
        }
        case 0:
            running = false;
            break;
        default:
            cout << "Неверный выбор.\n";
        }
    }
}
