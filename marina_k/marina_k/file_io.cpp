#include "file_io.hpp"
#include <fstream>
#include <sstream>

using namespace std;

bool load_db(const string& filename, vector<Univer>& db) {
    setlocale(LC_ALL, "Russian");
    ifstream fin(filename);
    if (!fin.is_open()) return false;

    db.clear();
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        Univer rec;
        string tmp;

        if (!getline(ss, rec.teacher, ';'))    break;
        if (!getline(ss, rec.subject, ';'))    break;
        if (!getline(ss, tmp, ';'))            break;
        rec.course = stoi(tmp);
        if (!getline(ss, tmp, ';'))            break;
        rec.semester = stoi(tmp);
        if (!getline(ss, rec.auditorium))      break;

        db.push_back(move(rec));
    }

    return true;
}

bool save_db(const string& filename, const vector<Univer>& db) {
    ofstream fout(filename);
    if (!fout.is_open()) return false;

    for (const auto& rec : db) {
        fout
            << rec.teacher << ';'
            << rec.subject << ';'
            << rec.course << ';'
            << rec.semester << ';'
            << rec.auditorium << '\n';
    }
    return true;
}
