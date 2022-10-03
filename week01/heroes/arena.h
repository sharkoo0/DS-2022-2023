#pragma once
#include "hero.h"

class Arena {
private:
    Hero** heroes;
    size_t size;
    size_t capacity = 8;

public:
    Arena() {
        size = 0;
        heroes = new Hero*[capacity];
    }
    Arena(const Arena& other) {
        size = other.size;
        heroes = new Hero*[capacity];
        for (size_t i = 0; i < size; ++i) {
            heroes[i] = other.heroes[i]->clone();
        }
    }
    Arena& operator=(const Arena& other) {
        if (this != &other) {
            for (int i = 0; i < size; ++i) {
                delete heroes[i];
            }
            delete[] heroes;
            size = other.size;
            heroes = new Hero*[capacity];
            for (size_t i = 0; i < size; ++i) {
                heroes[i] = other.heroes[i]->clone();
            }
        }

        return *this;
    }
    Arena(Hero** _heroes, size_t _size) {
        size = _size;
        heroes = new Hero*[capacity];
        for (size_t i = 0; i < size; ++i) {
            heroes[i] = _heroes[i]->clone();
        }
    }
    ~Arena() {
        for (int i = 0; i < size; ++i) {
            delete heroes[i];
        }
        delete[] heroes;
    }

    void fight() {
        for (int i = 0; i < size; ++i) {
            if (heroes[i]->getHealth() > 0) {
                for (int j = 0; j < size; ++j) {
                    if (i != j) {
                        heroes[i]->attack(heroes[j]);
                    }
                }
            }
            getInfo();
        }
    }

    void getInfo() const {
        for (int k = 0; k < size; ++k) {
            heroes[k]->getInfo();
        }
    }
};