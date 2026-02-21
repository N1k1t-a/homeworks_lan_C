#include "my_settings.h"
#include <stdexcept>
#include <fstream> 
#include <sstream>
#include <string>
#include <initializer_list>
#include <limits>


MySettings::~MySettings() {
    int_settings.clear();
    str_settings.clear();
}

void MySettings::add(const std::string& name, int value) {
    int_settings[name] = value;
}

void MySettings::add(const std::string& name, const std::string& value) {
    str_settings[name] = value;
}

void MySettings::erase_int(const std::string& name) {
    int_settings.erase(name);
}

void MySettings::erase_str(const std::string& name) {
    str_settings.erase(name);
}

int MySettings::find_int(const std::string& name) const {
    auto it = int_settings.find(name);  // ищем элемент

    if (it != int_settings.end()) {  // нашли?
        return it->second;  // возвращаем ЗНАЧЕНИЕ из пары
    }

    // Не нашли - бросаем исключение
    throw std::runtime_error("Int setting '" + name + "' not found!");
}

std::string MySettings::find_str(const std::string& name) const {
    auto it = str_settings.find(name);  // ищем элемент

    if (it != str_settings.end()) {  // нашли?
        return it->second;  // возвращаем ЗНАЧЕНИЕ из пары
    }

    // Не нашли - бросаем исключение
    throw std::runtime_error("String setting '" + name + "' not found!");
}

std::ostream& operator<<(std::ostream& os, const MySettings& settings) {
    os << "=== Settings ===" << std::endl;

    if (!settings.int_settings.empty()) {
        os << "Integer settings:" << std::endl;
        for (const auto& pair : settings.int_settings) {
            os << "  " << pair.first << ": " << pair.second << std::endl;
        }
    }

    if (!settings.str_settings.empty()) {
        os << "String settings:" << std::endl;
        for (const auto& pair : settings.str_settings) {
            os << "  " << pair.first << ": " << pair.second << std::endl;
        }
    }

    return os;
}


void MySettings::save(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    for (const auto& pair : int_settings) {
        file << "INT " << pair.first << " " << pair.second << std::endl;
    }

    for (const auto& pair : str_settings) {
        file << "STR " << pair.first << " " << pair.second << std::endl;
    }

    file.close();
}


void MySettings::load(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for reading: " + filename);
    }

    std::string type;
    std::string name;

    while (file >> type) {

        if (type == "INT") {
            int value;
            file >> name >> value;
            add(name, value);
        }
        else if (type == "STR") {
            std::string value;
            file >> name;
            std::getline(file, value);

            if (!value.empty() && value[0] == ' ') {
                value = value.substr(1);
            }

            add(name, value);
        }
    }

    file.close();
}


std::istream& operator>>(std::istream& is, MySettings& settings) {
    std::string token;
    while (is >> token) {
        if (token == "INT") {
            std::string name;
            int value;
            if (!(is >> name >> value)) {
                is.setstate(std::ios::failbit);
                break;
            }
            settings.add(name, value);
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (token == "STR") {
            std::string name;
            if (!(is >> name)) {
                is.setstate(std::ios::failbit);
                break;
            }
            std::string value;
            std::getline(is, value);
            if (!value.empty() && value[0] == ' ')
                value.erase(0, 1);
            settings.add(name, value);
        }
        else if (!token.empty() && token[0] == '#') {
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return is;
}

void MySettings::save_selected(const std::string& filename,
    std::initializer_list<std::string> keys) const
{
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    for (const auto& k : keys) {
        auto it = int_settings.find(k);
        if (it != int_settings.end()) {
            file << "INT " << it->first << " " << it->second << "\n";
            continue;
        }

        auto it2 = str_settings.find(k);
        if (it2 != str_settings.end()) {
            file << "STR " << it2->first << " " << it2->second << "\n";
            continue;
        }

        file << "# SKIP missing key: " << k << "\n";
    }
}