#pragma once
#include <iostream>

template <class T>
class Stack {
private:
    size_t size;
    size_t capacity;
    T* data;

private:
    void copy(const Stack<T>& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    void erase() {
        delete[] data;
    }

    void resize() {
        capacity *= 2;
        T* temp = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
    }

public:
    Stack() {
        size = 0;
        capacity = 8;
        data = new T[capacity];
    }
    Stack(const Stack<T>& other) {
        copy(other);
    }
    Stack<T>& operator=(const Stack<T>& other) {
        if (this != &other) {
            erase();
            copy(other);
        }

        return *this;
    }
    ~Stack() {
        erase();
    }

    void push(const T& element) {
        if (size == capacity) {
            resize();
        }

        data[size++] = element;
    }
    T& peek() const {
        if (isEmpty()) {
            throw "Cannot peek, Stack is empty";
        }
        return data[size - 1];
    }
    T& pop() {
        if (isEmpty()) {
            throw "Cannot pop, Stack is empty";
        }
        return data[--size];
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }
};