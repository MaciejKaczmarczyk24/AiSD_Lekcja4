#include <iostream>
#include <cassert>
#include "singlelist.hpp"

int main() {
    SingleList<int> list;
    
    assert(list.empty());
    assert(list.size() == 0);

    list.push_back(10);
    list.push_back(30);
    assert(list.size() == 2);
    assert(list.back() == 30);
    assert(list.front() == 10);

    list.push_front(5);
    assert(list.size() == 3);
    assert(list.front() == 5);
    assert(list[1] == 10);

    list.insert(2, 20);
    assert(list.size() == 4);
    assert(list[2] == 20);

    assert(list.index(20) == 2);
    assert(list.index(99) == -1);

    list.erase(1);
    assert(list.size() == 3);
    assert(list[1] == 20);

    list.pop_front();
    assert(list.front() == 20);
    
    list.pop_back();
    assert(list.back() == 20);
    assert(list.size() == 1);

    list.clear();
    assert(list.empty());

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.reverse();
    assert(list[0] == 3);
    assert(list[2] == 1);

    return 0;
}