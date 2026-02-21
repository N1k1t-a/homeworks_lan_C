#include "set.h"
#include <string>
#include <iostream>
#include <sstream>

struct Point {
    int x;
    int y;
    int z;

    Point(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }

    bool operator>(const Point& other) const {
        return other < *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        return os << "(" << p.x << "," << p.y << "," << p.z << ")";
    }
};

void testPrimitiveTypes() {
    std::cout << "\n=== ТЕСТИРОВАНИЕ ПРИМИТИВНЫХ ТИПОВ ===\n";

    std::cout << "\n1. Тест с int:\n";
    Set<int> intSet;
    intSet.insert(5);
    intSet.insert(2);
    intSet.insert(8);
    intSet.insert(2);
    intSet.insert(1);

    std::cout << "Set<int>: " << intSet << std::endl;
    std::cout << "Размер: " << intSet.size() << std::endl;
    std::cout << "Поиск 2: " << (intSet.find(2) ? "найден" : "не найден") << std::endl;
    std::cout << "Поиск 10: " << (intSet.find(10) ? "найден" : "не найден") << std::endl;

    std::cout << "\n2. Тест с double:\n";
    Set<double> doubleSet;
    doubleSet.insert(3.14159);
    doubleSet.insert(2.71828);
    doubleSet.insert(1.41421);
    doubleSet.insert(3.14159);

    std::cout << "Set<double>: " << doubleSet << std::endl;
    std::cout << "Размер: " << doubleSet.size() << std::endl;

    std::cout << "\n3. Тест с char:\n";
    Set<char> charSet;
    charSet.insert('z');
    charSet.insert('a');
    charSet.insert('m');
    charSet.insert('a');
    charSet.insert('b');

    std::cout << "Set<char>: " << charSet << std::endl;
    std::cout << "Размер: " << charSet.size() << std::endl;

    std::cout << "\n4. Тест с float:\n";
    Set<float> floatSet;
    floatSet.insert(1.5f);
    floatSet.insert(2.5f);
    floatSet.insert(1.0f);

    std::cout << "Set<float>: " << floatSet << std::endl;

    std::cout << "\n5. Тест с bool:\n";
    Set<bool> boolSet;
    boolSet.insert(true);
    boolSet.insert(false);
    boolSet.insert(true);

    std::cout << "Set<bool>: " << boolSet << std::endl;
    std::cout << "Размер: " << boolSet.size() << std::endl;
}

void testStringType() {
    std::cout << "\n=== ТЕСТИРОВАНИЕ СО СТРОКАМИ ===\n";

    std::vector<std::string> words = { "hello", "world", "test", "hello", "programming", "abc" };
    Set<std::string> stringSet(words);

    std::cout << "Set<string> из вектора: " << stringSet << std::endl;
    std::cout << "Размер: " << stringSet.size() << std::endl;

    stringSet.insert("new_word");
    std::cout << "После добавления 'new_word': " << stringSet << std::endl;

    std::cout << "Поиск 'hello': " << (stringSet.find("hello") ? "найдено" : "не найдено") << std::endl;
    std::cout << "Поиск 'xyz': " << (stringSet.find("xyz") ? "найдено" : "не найдено") << std::endl;
}

void testPointStruct() {
    std::cout << "\n=== ТЕСТИРОВАНИЕ СО STRUCT POINT ===\n";

    Set<Point> pointSet;

    pointSet.insert(Point(1, 2, 3));
    pointSet.insert(Point(0, 1, 2));
    pointSet.insert(Point(2, 3, 4));
    pointSet.insert(Point(1, 2, 3));
    pointSet.insert(Point(-1, 0, 1));
    pointSet.insert(Point(0, 0, 0));

    std::cout << "Set<Point>: " << pointSet << std::endl;
    std::cout << "Размер: " << pointSet.size() << std::endl;

    // Тест поиска
    Point searchPoint(1, 2, 3);
    std::cout << "Поиск точки (1,2,3): " << (pointSet.find(searchPoint) ? "найдена" : "не найдена") << std::endl;

    Point notExistPoint(10, 10, 10);
    std::cout << "Поиск точки (10,10,10): " << (pointSet.find(notExistPoint) ? "найдена" : "не найдена") << std::endl;

    std::vector<Point> points = {
        Point(5, 5, 5),
        Point(1, 1, 1),
        Point(3, 3, 3),
        Point(1, 1, 1)
    };

    Set<Point> pointSetFromVector(points);
    std::cout << "Set<Point> из вектора: " << pointSetFromVector << std::endl;
}

void testCopyAndAssignment() {
    std::cout << "\n=== ТЕСТИРОВАНИЕ КОПИРОВАНИЯ И ПРИСВАИВАНИЯ ===\n";

    Set<int> original;
    original.insert(10);
    original.insert(20);
    original.insert(30);

    std::cout << "Оригинальное множество: " << original << std::endl;

    Set<int> copied(original);
    std::cout << "Скопированное множество: " << copied << std::endl;

    Set<int> assigned;
    assigned.insert(100);
    assigned.insert(200);
    std::cout << "До присваивания: " << assigned << std::endl;

    assigned = original;
    std::cout << "После присваивания: " << assigned << std::endl;

    original.insert(40);
    std::cout << "\nПосле добавления 40 в оригинал:" << std::endl;
    std::cout << "Оригинал: " << original << std::endl;
    std::cout << "Копия: " << copied << std::endl;
    std::cout << "Присвоенная: " << assigned << std::endl;
}

void testIntersection() {
    std::cout << "\n=== ТЕСТИРОВАНИЕ ПЕРЕСЕЧЕНИЙ ===\n";

    Set<int> set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);

    Set<int> set2;
    set2.insert(3);
    set2.insert(4);
    set2.insert(5);
    set2.insert(6);

    std::cout << "Множество 1: " << set1 << std::endl;
    std::cout << "Множество 2: " << set2 << std::endl;

    try {
        Set<int> intersection = set1.intersect(set2);
        std::cout << "Пересечение: " << intersection << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }

    std::cout << "\nТест с пустым множеством:\n";
    Set<int> emptySet;
    try {
        Set<int> intersection = set1.intersect(emptySet);
        std::cout << "Пересечение: " << intersection << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Ожидаемая ошибка: " << e.what() << std::endl;
    }

    std::cout << "\nТест без общих элементов:\n";
    Set<int> set3;
    set3.insert(10);
    set3.insert(11);

    try {
        Set<int> intersection = set1.intersect(set3);
        std::cout << "Пересечение: " << intersection << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Ожидаемая ошибка: " << e.what() << std::endl;
    }
}

void testinput() {
    std::cout << "Тестирование оператор ввода\n";
    std::cout << "==========================================\n";

    std::istringstream iss("{ 3, 1, 2, }");
    Set<int> s;
    iss >> s;
    std::cout << s << "\n"; 
}

void testUnionPlus() {
    std::cout << "\n=== ТЕСТ ОПЕРАТОРА + (ОБЪЕДИНЕНИЕ) ===\n";
    Set<int> a; a.insert(1); a.insert(3); a.insert(5);
    Set<int> b; b.insert(2); b.insert(3); b.insert(4);

    std::cout << "A: " << a << "\n";
    std::cout << "B: " << b << "\n";

    Set<int> u = a + b;
    std::cout << "A + B: " << u << "  (ожидание: { 1, 2, 3, 4, 5, })\n";
}


void testDifferenceMinus() {
    std::cout << "\n=== ТЕСТ ОПЕРАТОРА - (РАЗНОСТЬ) ===\n";
    Set<int> a; a.insert(1); a.insert(2); a.insert(3); a.insert(4); a.insert(5);
    Set<int> b; b.insert(2); b.insert(4); b.insert(6);

    std::cout << "A: " << a << "\n";
    std::cout << "B: " << b << "\n";

    Set<int> d1 = a - b;
    Set<int> d2 = b - a;

    std::cout << "A - B: " << d1 << "  (ожидание: { 1, 3, 5, })\n";
    std::cout << "B - A: " << d2 << "  (ожидание: { 6, })\n";
}

void testReplace() {
    std::cout << "\n=== ТЕСТ replace(old, new) ===\n";
    Set<int> s;
    s.insert(1); s.insert(3); s.insert(5);
    std::cout << "Начальное: " << s << "\n";

    bool r1 = s.replace(3, 4);
    std::cout << "replace(3, 4) -> " << (r1 ? "ok" : "нет") << "  => " << s << "  (ожидание: { 1, 4, 5, })\n";

    bool r2 = s.replace(4, 5);
    std::cout << "replace(4, 5) -> " << (r2 ? "ok" : "нет") << "  => " << s << "  (ожидание: { 1, 5, })\n";

    bool r3 = s.replace(42, 7);
    std::cout << "replace(42, 7) -> " << (r3 ? "ok" : "нет") << "  => " << s << "  (ожидание: { 1, 5, })\n";

    bool r4 = s.replace(1, 1);
    std::cout << "replace(1, 1) -> " << (r4 ? "ok" : "нет") << "  => " << s << "  (ожидание: { 1, 5, })\n";
}


int main() {
    system("chcp 1251");
    std::cout << "ДЕМОНСТРАЦИЯ РАБОТЫ ШАБЛОННОГО КЛАССА SET\n";
    std::cout << "==========================================\n";

    testPrimitiveTypes();

    testStringType();

    testPointStruct();

    testinput();

    testDifferenceMinus();

    testUnionPlus();

    testCopyAndAssignment();

    testReplace();

    testIntersection();

    std::cout << "\n==========================================\n";
    std::cout << "ВСЕ ТЕСТЫ ЗАВЕРШЕНЫ УСПЕШНО!\n";

    return 0;
}

//Сделать реализацию множества set(на основе массива с сортировкой) для хранения только уникальных элементов.
//insert(const T& value)
//bool find(const T& value)
//size() возвращает количество элементов в множестве
//set intersect(const set& s) -- - пересечение(бросает исключение при пересечении с пустым множеством)
//operator<< для вывода
// перегрузить оператор ввода плюса минуса добавить функцию найти и заменгить 
