#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdexcept>

#include "List.h"

template <typename T>
class LinkedList : public List<T> {
   private:
    class Node {
       public:
        Node *next = nullptr;
        Node *prev = nullptr;
        T value;
        Node(const T &v) { value = v; }
    };
    Node *head = nullptr;
    Node *rear = nullptr;
    size_t __length = 0;
    // 缓存指针，减少读取时间
    Node *__p = nullptr;
    size_t __n = 0;

   public:
    // 构造
    LinkedList() = default;
    LinkedList(const T &v) { push_back(v); }
    template <typename... Targs>
    LinkedList(const Targs &...args) {
        push_back(args...);
    }

    // 查询
    bool empty() const { return __length == 0; }
    size_t length() const { return __length; }

    T &front() {
        if (empty()) throw std::out_of_range(EMPTY_LIST);
        return head->value;
    }
    T &back() {
        if (empty()) throw std::out_of_range(EMPTY_LIST);
        return rear->value;
    }
    Node *node(size_t n) {
        if (empty() || n >= __length)
            throw std::out_of_range(GET_OUT_OF_RANGE);
        else if (n == 0)
            return head;
        else if (n == __length - 1)
            return rear;

        if (__p == nullptr) __p = head;
        if (n == __n)
            return __p;
        else if (__n < n)
            for (; __n != n; ++__n) __p = __p->next;
        else if (__n > n)
            for (; __n != n; --__n) __p = __p->prev;
        return __p;
    }
    T &operator[](size_t n) { return node(n)->value; }

    // 增删
    void push_front(const T &v) {
        if (empty()) {
            head = rear = new Node(v);
        } else {
            head->prev = new Node(v);
            head->prev->next = head;
            head = head->prev;
        }
        ++__n;
        ++__length;
    }
    void push_back(const T &v) {
        if (empty()) {
            rear = head = new Node(v);
        } else {
            rear->next = new Node(v);
            rear->next->prev = rear;
            rear = rear->next;
        }
        ++__length;
    }
    T pop_front() {
        if (empty()) throw std::out_of_range(EMPTY_LIST);
        auto t = head->value;
        if (head == rear) {
            delete head;
            head = rear = nullptr;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        if (__n == 0) __p == head;
        --__length;
        return t;
    }
    T pop_back() {
        if (empty()) throw std::out_of_range(EMPTY_LIST);
        auto t = rear->value;
        if (rear == head) {
            delete rear;
            rear = head = nullptr;
        } else {
            rear = rear->prev;
            delete rear->next;
            rear->next = nullptr;
        }
        --__length;
        return t;
    }
    void insert(size_t n, const T &v) {
        if (n > __length)
            throw std::out_of_range(INSERT_OUT_OF_RANGE);
        else if (empty() || n == __length)
            push_back(v);
        else if (n == 0)
            push_front(v);
        else {
            auto p = node(n);
            auto t = new Node(v);
            t->next = p;
            t->prev = p->prev;
            t->next->prev = t;
            t->prev->next = t;
            ++__n;
            ++__length;
        }
    }
    void remove(size_t n) {
        if (n > __length)
            throw std::out_of_range(REMOVE_OUT_OF_RANGE);
        else if (n == __length - 1)
            pop_back();
        else if (n == 0)
            pop_front();
        else {
            auto p = node(n);
            __p = __p->prev;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            --__n;
            --__length;
        }
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