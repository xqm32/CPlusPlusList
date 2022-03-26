#include <ctime>

#include "LinkedList.h"
#include "SequenceList.h"
#include "Sort.h"
#include "TestList.h"

template <template <typename> typename T, typename F>
double test(F func, size_t n) {
    auto listA = T<int>();
    auto listB = T<int>();
    generateList(listA, n);
    generateList(listB, n);
    auto timeA = clock();
    func(listA, listB);
    auto timeB = clock();
    return 1000.0 * (timeB - timeA) / CLOCKS_PER_SEC;
}

void finishMyHomework(size_t n) {
    auto seed = time(NULL);
    srand(seed);
    printf("对含有 %ld 个整数的两个链表合并后排序花费 %lf ms\n", n * 2,
           test<LinkedList>(mergeSort<int>, n));
    srand(seed);
    printf("对含有 %ld 个整数的两个链表排序后合并花费 %lf ms\n", n * 2,
           test<LinkedList>(sortMerge<int>, n));
    srand(seed);
    printf("对含有 %ld 个整数的两个顺序表合并后排序花费 %lf ms\n", n * 2,
           test<SequenceList>(mergeSort<int>, n));
    srand(seed);
    printf("对含有 %ld 个整数的两个顺序表排序后合并花费 %lf ms\n", n * 2,
           test<SequenceList>(sortMerge<int>, n));
}

int main() {
    finishMyHomework(100);
    finishMyHomework(1000);
    finishMyHomework(10000);
}