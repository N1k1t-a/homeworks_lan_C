#ifndef FILE_IO_HPP
#define FILE_IO_HPP
#include <vector>
#include <string>
#include "record.hpp"

using namespace std;

bool load_db(const string& filename, vector<Univer>& db);


bool save_db(const string& filename, const vector<Univer>& db);

#endif 
