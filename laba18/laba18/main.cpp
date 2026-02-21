#include "my_settings.h"
#include <iostream>
#include <sstream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "RU");

    std::cout << "=== Тест 1: Добавление настроек ===" << std::endl;

    MySettings settings;

    settings.add("color", 34);
    settings.add("width", 1920);
    settings.add("height", 1080);

    settings.add("path", "c:\\labs");
    settings.add("name", "MyProgram");
    settings.add("author", "Student");

    std::cout << settings << std::endl;


    std::cout << "\n=== Тест 2: Поиск настроек ===" << std::endl;

    try {
        int color = settings.find_int("color");
        std::cout << "color = " << color << std::endl;

        std::string path = settings.find_str("path");
        std::cout << "path = " << path << std::endl;

        // Попытка найти несуществующую настройку
        int nonexistent = settings.find_int("nonexistent");
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }


    std::cout << "\n=== Тест 3: Удаление настроек ===" << std::endl;

    settings.erase_int("color");
    settings.erase_str("author");

    std::cout << "После удаления:" << std::endl;
    std::cout << settings << std::endl;


    std::cout << "\n=== Тест 4: Сохранение в файл ===" << std::endl;

    settings.save("config.txt");
    std::cout << "Настройки сохранены в config.txt" << std::endl;


    std::cout << "\n=== Тест 5: Загрузка из файла ===" << std::endl;

    MySettings loaded;
    loaded.load("config.txt");

    std::cout << "Загруженные настройки:" << std::endl;
    std::cout << loaded << std::endl;


    std::cout << "\n=== Тест 6: Перезапись существующих настроек ===" << std::endl;

    loaded.add("width", 2560);
    loaded.add("path", "d:\\projects");

    std::cout << "После изменения:" << std::endl;
    std::cout << loaded << std::endl;


    std::cout << "\n=== Тест 7: Работа с пустым объектом ===" << std::endl;

    MySettings empty;
    std::cout << empty << std::endl;

    try {
        empty.find_int("test");
    }
    catch (const std::exception& e) {
        std::cout << "Ожидаемая ошибка: " << e.what() << std::endl;
    }

    std::cout << "\n=== Тест 8: Ввод оператором >> ===" << std::endl;
    std::ifstream fin("config.txt");
    if (fin) {
        MySettings fromFileOp;
        fin >> fromFileOp;
        std::cout << "Загружено оператором >>:" << std::endl;
        std::cout << fromFileOp << std::endl;
    }
    else {
        std::cout << "Не удалось открыть config.txt для чтения оператором >>" << std::endl;
    }

    std::cout << "\n=== Тест 9: Сохранение ВЫБРАННЫХ настроек в новый файл ===\n";

    settings.save_selected("config_selected.txt", {
        "color",
        "width",  
        "path",  
        "author", 
        "nonexistent"
        });

    std::cout << "Выбранные настройки сохранены в config_selected.txt\n";

    std::cout << "\n=== Все тесты завершены! ===" << std::endl;

    std::istringstream iss(
        "INT color 90\n"
        "STR path C:\\\\new path\n"
        "STR title Hello world\n"
        "# comment line\n"
        "INT height 720\n"
    );
    MySettings viaStream;
    iss >> viaStream;
    std::cout << viaStream << std::endl;


    return 0;
}


//Реализовать класс для хранения настроек : имя настройки, значение настройки.Может быть два варианта настроек : 
// строка-- - число(“color”, 34) и строка - строка(“path”, “c:\labs”).
//add(const std::string & name, int value)
//add(const std::string & name, const std::string & value)
//erase_int(const std::string & name)
//erase_str(const std::string & name)
//int find_int(const std::string & name)
//std::string find_str(const std::string & name)
//operator<< для вывода на экран
//load(const std::string & filename) //загрузка из файла
//save(const std::string & filename)
