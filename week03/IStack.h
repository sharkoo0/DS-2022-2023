#pragma once

template <class T>
class IStack {
public:
    virtual void push(const T& element) = 0;
    virtual T& pop() = 0;
    virtual T& peek() const = 0;

    virtual bool isEmpty() const = 0;
};


