#pragma once
#include "hero.h"

class Warrior : public Hero {
private:
    int fury;

public:
    Warrior() : Hero(120), fury(0) {}
    Warrior(const char* name, int health, int _fury) : Hero(name, health), fury(_fury) {}
    Warrior(const Warrior& other) : Hero(other), fury(other.fury) {}
    Warrior& operator=(const Warrior& other) {
        if (this != &other) {
            Hero::operator=(other);
            fury = other.fury;
        }

        return *this;
    }
    ~ Warrior() {}

    Hero* clone() const override {
        return new Warrior(*this);
    }

    int getFury() const {
        return fury;
    }

    void getInfo() const {
        Hero::getInfo();
        std::cout << " fury: " << fury << std::endl;
    }

    void attack(Hero* enemy) override {
        enemy->setHealth(enemy->getHealth() - (fury + 10));
        fury += 20;
    }

};