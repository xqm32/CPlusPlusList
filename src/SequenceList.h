#ifndef __SEQUENCELIST_H__
#define __SEQUENCELIST_H__

#include <stdexcept>

#include "List.h"

#define MAX_LENGTH 65536
#define MOVE_OUT_OF_RANGE "Move out of range"

template <typename T>
class SequenceList : public List<T> {
   private:
    T __array[MAX_LENGTH];
    size_t __length = 0;

    void move(size_t f, ptrdiff_t n) {
        if (__length + n > MAX_LENGTH || __length + n < 0)
            throw std::out_of_range(MOVE_OUT_OF_RANGE);
        else if (n > 0)
            // 这里必须用 +n 的方式，否则将溢出
            for (auto i = __length - 1 + n; i >= f + n; --i)
                __array[i] = __array[i - n];
        else if (n < 0)
            for (auto i = f; i < __length; ++i) __array[i + n] = __array[i];
        __length += n;
    }

   public:
    // 构造
    SequenceList() = default;
    SequenceList(const T &v) { push_back(v); }
    template <typename... Targs>
    SequenceList(const Targs &...args) {
        push_back(args...);
    }

    // 查询
    bool empty() const { return __length == 0; }
    bool full() const { return __length == MAX_LENGTH; }
    size_t length() const { return __length; }

    T &front() {
        if (empty()) throw std::out_of_range(EMPTY_LIST);
        return __array[0];
    }
    T &back() {
        if (empty()) throw std::out_of_range(EMPTY_LIST);
        return __array[__length - 1];
    }
    T &operator[](size_t n) {
        if (empty() || n >= __length) throw std::out_of_range(GET_OUT_OF_RANGE);
        return __array[n];
    }

    // 增删
    void push_front(const T &v) {
        if (full()) throw std::length_error(FULL_LIST);
        move(0, 1);
        __array[0] = v;
    }
    void push_back(const T &v) {
        if (full()) throw std::length_error(FULL_LIST);
        __array[__length++] = v;
    }
    T pop_front() {
        if (empty()) throw std::out_of_range(EMPTY_LIST);
        auto t = __array[0];
        move(1, -1);
        return t;
    }
    T pop_back() {
        if (empty()) throw std::out_of_range(EMPTY_LIST);
        return __array[--__length];
    }
    void insert(size_t n, const T &v) {
        if (n > __length)
            throw std::out_of_range(INSERT_OUT_OF_RANGE);
        else if (n == __length)
            push_back(v);
        else if (n == 0)
            push_front(v);
        else {
            move(n, 1);
            __array[n] == v;
        }
    }
    // 从第 n+1 个开始，每个向前移动一格（覆盖元素 n）
    void remove(size_t n) {
        if (empty())
            throw std::out_of_range(EMPTY_LIST);
        else if (n > __length)
            throw std::out_of_range(REMOVE_OUT_OF_RANGE);
        else if (n == __length)
            pop_back();
        else if (n == 0)
            pop_front();
        else
            move(n + 1, -1);
    }

    // 依赖于前置实现的函数
    template <typename... Targs>
    void push_front(const T &v, const Targs &...args) {
        push_front(v);
        push_front(args...);
    }
    template <typename... Targs>
    void push_back(const T &v, const Targs &...args) {
        push_back(v);
        push_back(args...);
    }
    void pop_front(size_t n) {
        while (n--) pop_front();
    }
    void pop_back(size_t n) {
        while (n--) pop_back();
    }
};

#endif