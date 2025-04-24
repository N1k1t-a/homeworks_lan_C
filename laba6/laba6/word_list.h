#ifndef WORD_LIST_H
#define WORD_LIST_H

#include <string>

struct Node {
    std::string word;
    Node* next;
};

struct List {
    Node* head;

    List() : head(nullptr) {}      
    ~List();                       
    List(const List& other);       

    void append(const std::string& word);
    void clear();
};


void readFileToList(const std::string& filename, List& list);
void mergeLists(const List& list1, const List& list2, List& result);
void sortList(List& list);
void sortListByLength(List& list); 


#endif 
