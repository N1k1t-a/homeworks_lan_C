#ifndef DB_OPS_HPP
#define DB_OPS_HPP

#include <vector>
#include <string>
#include "record.hpp"

using namespace std;

void view_db(const vector<Univer>& db);


void sort_by_course(vector<Univer>& db, bool ascending);
void sort_by_semester(vector<Univer>& db, bool ascending);


vector<Univer> search_by_subject(
    const vector<Univer>& db,
    const string& query
);

double average_course(const vector<Univer>& db);
double average_semester(const vector<Univer>& db);
Univer max_course_record(const vector<Univer>& db);
Univer min_course_record(const vector<Univer>& db);
Univer max_semester_record(const vector<Univer>& db);
Univer min_semester_record(const vector<Univer>& db);

#endif

