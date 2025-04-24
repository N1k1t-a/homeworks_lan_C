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

    std::cout << "���������� ������� ������:" << std::endl;
    Node* current = list1.head;
    while (current) {
        std::cout << current->word << " ";
        current = current->next;
    }
    std::cout << std::endl;

    std::cout << "���������� ������� ������:" << std::endl;
    current = list2.head;
    while (current) {
        std::cout << current->word << " ";
        current = current->next;
    }
    std::cout << std::endl;

    std::cout << "����������� � ��������������� ������:" << std::endl;
    current = mergedList.head;
    while (current) {
        std::cout << current->word << " ";
        current = current->next;
    }
    std::cout << std::endl;

    sortListByLength(mergedList);

    std::cout << "����������� � ��������������� �� ����� ������:" << std::endl;
    current = mergedList.head;
    while (current) {
        std::cout << current->word << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}


//�������� ���������, ������������ �� ���� ���������
//������ �������� ������������� ������ ��������� ���� � ������� 
//������������ �������.������ ������������ ������ �� �����.
// ��� �������
// ��� ������� ���������� �� �������� � �����
// ����������� �����