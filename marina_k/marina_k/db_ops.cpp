#include "db_ops.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;


void view_db(const vector<Univer>& db) {
    setlocale(LC_ALL, "Russian");
    if (db.empty()) {
        cout << "База данных пуста.\n";
        return;
    }
    cout
        << "+----+----------------------+----------------------+--------+----------+----------------+\n"
        << "| №  | Преподаватель        | Дисциплина           | Курс   | Семестр  | Аудитория      |\n"
        << "+----+----------------------+----------------------+--------+----------+----------------+\n";
    for (size_t i = 0; i < db.size(); ++i) {
        const auto& r = db[i];
        cout
            << "| " << setw(2) << i + 1
            << " | " << setw(20) << r.teacher
            << " | " << setw(20) << r.subject
            << " | " << setw(6) << r.course
            << " | " << setw(8) << r.semester
            << " | " << setw(14) << r.auditorium
            << " |\n";
    }
    cout
        << "+----+----------------------+----------------------+--------+----------+----------------+\n";
}

void sort_by_course(vector<Univer>& db, bool asc) {
    sort(db.begin(), db.end(),
        [asc](auto& a, auto& b) {
            return asc ? (a.course < b.course) : (a.course > b.course);
        }
    );
}
void sort_by_semester(vector<Univer>& db, bool asc) {
    sort(db.begin(), db.end(),
        [asc](auto& a, auto& b) {
            return asc ? (a.semester < b.semester) : (a.semester > b.semester);
        }
    );
}


vector<Univer> search_by_subject(
    const vector<Univer>& db,
    const string& query
) {
    vector<Univer> res;
    for (auto& r : db)
        if (r.subject.find(query) != string::npos)
            res.push_back(r);
    return res;
}


double average_course(const vector<Univer>& db) {
    if (db.empty()) return 0.0;
    double sum = 0;
    for (auto& r : db) sum += r.course;
    return sum / db.size();
}
double average_semester(const vector<Univer>& db) {
    if (db.empty()) return 0.0;
    double sum = 0;
    for (auto& r : db) sum += r.semester;
    return sum / db.size();
}
Univer max_course_record(const vector<Univer>& db) {
    return *max_element(db.begin(), db.end(),
        [](auto& a, auto& b) { return a.course < b.course; }
    );
}
Univer min_course_record(const vector<Univer>& db) {
    return *min_element(db.begin(), db.end(),
        [](auto& a, auto& b) { return a.course < b.course; }
    );
}
Univer max_semester_record(const vector<Univer>& db) {
    return *max_element(db.begin(), db.end(),
        [](auto& a, auto& b) { return a.semester < b.semester; }
    );
}
Univer min_semester_record(const vector<Univer>& db) {
    return *min_element(db.begin(), db.end(),
        [](auto& a, auto& b) { return a.semester < b.semester; }
    );
}
