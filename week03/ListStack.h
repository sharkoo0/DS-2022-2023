#pragma once
#include <list>

template <class T>
class ListStack : public IStack<T> {
private:
    std::list<T> data;

public:
    void push(const T& element) {
        data.push_back(element);
    }
    T& pop() {
        T temp = data.back();
        data.pop_back();
        return temp;
    }
    T& peek() const {
        return data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }
};