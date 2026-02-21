#include <iostream>
#include <list>
#include <set>

void removeNegative(std::list<int>& l) {
    
    for (auto i = l.begin(); i != l.end();)

        if (*i < 0) {
            i = l.erase(i);
        }
        else
            i++;
}

void insertBeforeEven(std::list<int>& l) {
    for (auto i = l.begin(); i != l.end(); i++) {
        if (*i % 2 == 0) {
            i = l.insert(i, 0);
            i++;
        }
    }
}

//int main() {
//    std::list<int> nums = { 1, 2, 3, 4, 5, 6 };
//
//    insertBeforeEven(nums);
//
//    // ќжидаемый вывод: 1 0 2 3 0 4 5 0 6
//    for (auto x : nums) {
//        std::cout << x << " ";
//    }
//
//    return 0;
//}


void removeDuplicates(std::list<int>& l) {
    std::set<int> aboba;

    for (auto i = l.begin(); i != l.end(); ++i)
        aboba.insert(*i);

}

//int main() {
//    std::list<int> nums = { 1, 2, 3, 2, 1, 4, 3, 5, 1 };
//
//    removeDuplicates(nums);
//
//    // ќжидаемый вывод: 1 2 3 4 5
//    for (auto x : nums) {
//        std::cout << x << " ";
//    }
//
//    return 0;
//}
