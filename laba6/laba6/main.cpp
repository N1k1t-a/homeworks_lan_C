#include <iostream>
#include "word_list.h"

int main() {
    setlocale(LC_ALL, "Ru");

    List list1, list2;
    readFileToList("file1.txt", list1); 
    readFileToList("file2.txt", list2); 

    List mergedList = list1;  
    mergeLists(list1, list2, mergedList);  

    sortList(mergedList);  

    std::cout << "Содержимое первого списка:" << std::endl;
    Node* current = list1.head;
    while (current) {
        std::cout << current->word << " ";
        current = current->next;
    }
    std::cout << std::endl;

    std::cout << "Содержимое второго списка:" << std::endl;
    current = list2.head;
    while (current) {
        std::cout << current->word << " ";
        current = current->next;
    }
    std::cout << std::endl;

    std::cout << "Объединённый и отсортированный список:" << std::endl;
    current = mergedList.head;
    while (current) {
        std::cout << current->word << " ";
        current = current->next;
    }
    std::cout << std::endl;

    sortListByLength(mergedList);

    std::cout << "Объединённый и отсортированный по длине список:" << std::endl;
    current = mergedList.head;
    while (current) {
        std::cout << current->word << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}


//Написать программу, составляющую по двум символьны
//файлам линейные упорядоченные списки различных слов и функцию 
//конкатенации списков.Выдать объединенный список на экран.
// доп задание
// две функции сортировки по алфивиту и длине
// конструктор копий