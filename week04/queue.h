#pragma once
#include <iostream>

template <class T>
class Queue {
private:
    T* data;
    size_t size;
    size_t capacity;

private:
    void copy(const Queue<T>& other) {
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
    Queue() {
        size = 0;
        capacity = 8;
        data = new T[capacity];
    }
    Queue(const Queue<T>& other) {
        copy(other);
    }
    Queue& operator=(const Queue<T>& other) {
        if (this != &other) {
            erase();
            copy(other);
        }

        return *this;
    }
    ~Queue() {
        erase();
    }

    void push(const T& element) {
        if (size == capacity) {
            resize();
        }
        data[size++] = element;
    }
    void pop() {
        if (isEmpty()) {
            throw "Cannot pop. Queue is empty.";
        }

        for (size_t i = 0; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }
    T& front() {
        if (isEmpty()) {
            throw "Cannot get front. Queue is empty.";
        }
        return data[0];
    }

    bool isEmpty() const {
        return size == 0;
    }
};