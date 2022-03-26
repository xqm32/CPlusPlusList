#include <cstdlib>
#include <ctime>

#include "LinkedList.h"
#include "SequenceList.h"
#include "Sort.h"
#include "TestList.h"

#define LIST_SIZE 1000

template <template <typename> typename T, typename F>
double test(F func) {
    auto listA = T<int>();
    auto listB = T<int>();
    generateList(listA, LIST_SIZE);
    generateList(listB, LIST_SIZE);
    auto timeA = clock();
    func(listA, listB);
    auto timeB = clock();
    return 1000.0 * (timeB - timeA) / CLOCKS_PER_SEC;
}

int main() {
    printf("对含有 %d 个整数的两个链表合并并排序花费 %lf ms\n", LIST_SIZE,
           test<LinkedList>(mergeSort<int>));
    printf("对含有 %d 个整数的两个链表排序并合并花费 %lf ms\n", LIST_SIZE,
           test<LinkedList>(mergeSort<int>));
    printf("对含有 %d 个整数的两个顺序表合并并排序花费 %lf ms\n", LIST_SIZE,
           test<SequenceList>(mergeSort<int>));
    printf("对含有 %d 个整数的两个顺序表合并并排序花费 %lf ms\n", LIST_SIZE,
           test<SequenceList>(sortMerge<int>));
}