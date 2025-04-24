#include <iostream>
#include <fstream>
#include "word_list.h"

List::~List() {
    clear();
}


List::List(const List& other) : head(nullptr) {
    Node* current = other.head;
    while (current) {
        this->append(current->word); 
        current = current->next;    
    }
}


void List::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::append(const std::string& word) {
    Node* newNode = new Node{ word, nullptr };
    if (!head) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void readFileToList(const std::string& filename, List& list) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return;
    }

    std::string word;
    while (file >> word) {
        list.append(word);
    }

    file.close();
}

void mergeLists(const List& list1, const List& list2, List& result) {
    Node* current = list1.head;
    while (current) {
        result.append(current->word);
        current = current->next;
    }

    current = list2.head;
    while (current) {
        result.append(current->word);
        current = current->next;
    }
}

void sortList(List& list) {
    if (!list.head || !list.head->next) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = list.head;
        while (current->next) {
            if (current->word > current->next->word) {
                std::swap(current->word, current->next->word);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}


void sortListByLength(List& list) {
    if (!list.head || !list.head->next) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = list.head;
        while (current->next) {
            if (current->word.length() > current->next->word.length()) {
                std::swap(current->word, current->next->word);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}
