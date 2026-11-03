#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

#include <iostream>
#include <cassert>
#include <utility>

template <typename T>
struct SingleNode {
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {}
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() = default;
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList();

    SingleList(const SingleList& other);
    SingleList(SingleList&& other);
    SingleList& operator=(const SingleList& other);
    SingleList& operator=(SingleList&& other);

    bool empty() const { return head == nullptr; }
    bool full() const { return false; }
    std::size_t size() const;
    void push_front(const T& item);
    void push_front(T&& item);
    void push_back(const T& item);
    void push_back(T&& item);
    T& front() { assert(!empty()); return head->value; }
    T& back() { assert(!empty()); return tail->value; }
    void pop_front();
    void pop_back();
    void clear();
    void display() const;
    void display_reversed();
    void reverse();

    T& operator[](std::size_t pos);
    const T& operator[](std::size_t pos) const;
    void erase(std::size_t pos);
    int index(const T& item);
    void insert(std::size_t pos, const T& item);
    void insert(std::size_t pos, T&& item);
};

template <typename T>
SingleList<T>::~SingleList() {
    clear();
}

template <typename T>
SingleList<T>::SingleList(const SingleList& other) : head(nullptr), tail(nullptr) {
    for (SingleNode<T>* node = other.head; node != nullptr; node = node->next) {
        push_back(node->value);
    }
}

template <typename T>
SingleList<T>::SingleList(SingleList&& other) : head(other.head), tail(other.tail) {
    other.head = nullptr;
    other.tail = nullptr;
}

template <typename T>
SingleList<T>& SingleList<T>::operator=(const SingleList& other) {
    if (this != &other) {
        clear();
        for (SingleNode<T>* node = other.head; node != nullptr; node = node->next) {
            push_back(node->value);
        }
    }
    return *this;
}

template <typename T>
SingleList<T>& SingleList<T>::operator=(SingleList&& other) {
    if (this != &other) {
        clear();
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}

template <typename T>
std::size_t SingleList<T>::size() const {
    std::size_t count = 0;
    for (SingleNode<T>* node = head; node != nullptr; node = node->next) {
        ++count;
    }
    return count;
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    head = new SingleNode<T>(item, head);
    if (tail == nullptr) tail = head;
}

template <typename T>
void SingleList<T>::push_front(T&& item) {
    head = new SingleNode<T>(std::move(item), head);
    if (tail == nullptr) tail = head;
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    SingleNode<T>* newNode = new SingleNode<T>(item);
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void SingleList<T>::push_back(T&& item) {
    SingleNode<T>* newNode = new SingleNode<T>(std::move(item));
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T>* node = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        SingleNode<T>* before = head;
        while (before->next != tail) {
            before = before->next;
        }
        delete tail;
        tail = before;
        tail->next = nullptr;
    }
}

template <typename T>
void SingleList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void SingleList<T>::display() const {
    for (SingleNode<T>* node = head; node != nullptr; node = node->next) {
        std::cout << node->value << " ";
    }
    std::cout << "\n";
}

template <typename T>
void SingleList<T>::reverse() {
    SingleNode<T>* prev = nullptr;
    SingleNode<T>* current = head;
    SingleNode<T>* next = nullptr;
    tail = head;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template <typename T>
void SingleList<T>::display_reversed() {
    reverse();
    display();
    reverse();
}

template <typename T>
T& SingleList<T>::operator[](std::size_t pos) {
    assert(pos < size());
    SingleNode<T>* node = head;
    for (std::size_t i = 0; i < pos; ++i) {
        node = node->next;
    }
    return node->value;
}

template <typename T>
const T& SingleList<T>::operator[](std::size_t pos) const {
    assert(pos < size());
    SingleNode<T>* node = head;
    for (std::size_t i = 0; i < pos; ++i) {
        node = node->next;
    }
    return node->value;
}

template <typename T>
void SingleList<T>::erase(std::size_t pos) {
    assert(pos < size());
    if (pos == 0) {
        pop_front();
    } else {
        SingleNode<T>* before = head;
        for (std::size_t i = 0; i < pos - 1; ++i) {
            before = before->next;
        }
        SingleNode<T>* toDelete = before->next;
        before->next = toDelete->next;
        if (toDelete == tail) {
            tail = before;
        }
        delete toDelete;
    }
}

template <typename T>
int SingleList<T>::index(const T& item) {
    SingleNode<T>* node = head;
    int idx = 0;
    while (node != nullptr) {
        if (node->value == item) return idx;
        node = node->next;
        ++idx;
    }
    return -1;
}

template <typename T>
void SingleList<T>::insert(std::size_t pos, const T& item) {
    assert(pos <= size());
    if (pos == 0) {
        push_front(item);
    } else if (pos == size()) {
        push_back(item);
    } else {
        SingleNode<T>* before = head;
        for (std::size_t i = 0; i < pos - 1; ++i) {
            before = before->next;
        }
        before->next = new SingleNode<T>(item, before->next);
    }
}

template <typename T>
void SingleList<T>::insert(std::size_t pos, T&& item) {
    assert(pos <= size());
    if (pos == 0) {
        push_front(std::move(item));
    } else if (pos == size()) {
        push_back(std::move(item));
    } else {
        SingleNode<T>* before = head;
        for (std::size_t i = 0; i < pos - 1; ++i) {
            before = before->next;
        }
        before->next = new SingleNode<T>(std::move(item), before->next);
    }
}

#endif
