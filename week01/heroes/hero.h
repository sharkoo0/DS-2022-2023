#pragma once
#include <iostream>
#include <cstring>

class Hero {
private:
    void copy(const Hero& other) {
        name = new char[strlen(other.name)];
        strcpy(name, other.name);
        health = other.health;
    }

    void erase() {
        delete[] name;
    }
protected:
    char* name;
    int health;

public:
    Hero(int _health = 100) {
        name = new char[8];
        strcpy(name, "Unknown");
        health = _health;
    }
    Hero(const char* _name, int _health) : health(_health) {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
    Hero(const Hero& other) {
        copy(other);
    }
    Hero& operator=(const Hero& other) {
        if (this != &other) {
            erase();
            copy(other);
        }

        return *this;
    }
    virtual ~Hero() {
        erase();
    }

    virtual Hero* clone() const = 0;

    int getHealth() const {
        return health;
    }

    void setHealth(int _health) {
        health = _health;
    }

    virtual void getInfo() const {
        std::cout << name << " health: " << health;
    }
    virtual void attack(Hero* enemy) = 0;
};