#define _CRT_SECURE_NO_WARNINGS
#include "ui.hpp"
#include <vector>
#include "record.hpp"
#include <iostream>

using namespace std;

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    vector<Univer> db;
    run_ui(db);
    return 0;
}
