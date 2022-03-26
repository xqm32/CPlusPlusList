#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

#define EMPTY_LIST "(Empty List)"
#define FULL_LIST "(Full list)"
#define LEFT_BRACKET "["
#define SEPARATOR ", "
#define RIGHT_BRACKET "]"

#define GET_OUT_OF_RANGE "Get out of range"
#define INSERT_OUT_OF_RANGE "REMOVE out of range"
#define REMOVE_OUT_OF_RANGE "REMOVE out of range"

template <typename T>
class List {
   public:
    virtual bool empty() const = 0;
    virtual size_t length() const = 0;
    virtual T &front() = 0;
    virtual T &back() = 0;
    virtual T &operator[](size_t) = 0;
    virtual void push_front(const T &) = 0;
    virtual void push_back(const T &) = 0;
    virtual T pop_front() = 0;
    virtual T pop_back() = 0;
    virtual void insert(size_t, const T &) = 0;
    virtual void remove(size_t) = 0;
    void print() {
        if (empty())
            std::cout << EMPTY_LIST << std::endl;
        else {
            std::cout << LEFT_BRACKET;
            for (auto i = 0; i < length() - 1; ++i)
                std::cout << (*this)[i] << SEPARATOR;
            std::cout << (*this)[length() - 1] << RIGHT_BRACKET << std::endl;
        }
    }
    void append(List<T> &l) {
        for (auto i = 0; i < l.length(); ++i) push_back(l[i]);
    }
};

#endif