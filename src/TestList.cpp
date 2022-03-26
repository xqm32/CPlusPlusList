#include "TestList.h"

#include "List.h"
#include "Sort.h"

#define RES(STH) std::cout << #STH << ": " << STH << std::endl;
#define LOG(STH)                    \
    std::cout << #STH << std::endl; \
    STH;
#define DO(STH) \
    LOG(STH);   \
    list.print();

void testLinkedList() {
    DO(LinkedList<int> list(8, 7, 6, 5, 4, 3, 2, 1));
    DO(list.push_front(0));
    DO(list.push_back(9));
    DO(list[0] = 2);
    DO(list.remove(7));
    DO(list.insert(0, 3));
    DO(list.insert(10, 9));
    DO(list.pop_front());
    DO(list.pop_back());
    DO(quickSort(list));
}

void testSequenceList() {
    DO(SequenceList<int> list(8, 7, 6, 5, 4, 3, 2, 1));
    DO(list.push_front(0));
    DO(list.push_back(9));
    DO(list[0] = 2);
    DO(list.remove(7));
    DO(list.insert(0, 3));
    DO(list.insert(10, 9));
    DO(list.pop_front());
    DO(list.pop_back());
    DO(quickSort(list));
}

void generateList(List<int> &list, size_t n) {
    while (n--) list.push_back(rand() % GENERATE_MAX);
}