#ifndef __SORT_H__
#define __SORT_H__

#include <algorithm>

#include "List.h"

template <typename T>
static void __quickSort(List<T> &array, size_t left, size_t right) {
    if (left >= right) return;
    auto i = left, j = right;
    auto base = array[left];
    while (i < j) {
        while (array[j] >= base && i < j) j--;
        while (array[i] <= base && i < j) i++;
        if (i < j) std::swap(array[i], array[j]);
    }

    array[left] = array[i];
    array[i] = base;
    // i 的类型是 size_t，通过加入判断防止整形溢出
    __quickSort(array, left, i > 0 ? i - 1 : 0);
    __quickSort(array, i + 1, right);
}

template <typename T>
void quickSort(List<T> &array) {
    __quickSort(array, 0, array.length() - 1);
}

template <typename T>
void sortMerge(List<T> &listA, List<T> &listB) {
    quickSort(listA);
    quickSort(listB);
    for (auto i = 0, j = 0; j < listB.length(); ++j) {
        while (i < listA.length() && listA[i] < listB[j]) ++i;
        listA.insert(i, listB[j]);
    }
}

template <typename T>
void mergeSort(List<T> &listA, List<T> &listB) {
    listA.append(listB);
    quickSort(listA);
}

#endif