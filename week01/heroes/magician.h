#pragma once
#include "hero.h"

class Magician : public Hero {
private:
    int mana;

public:
    Magician() : Hero(), mana(200) {}
    Magician(const char* name, int health, int _mana) : Hero(name, health), mana(_mana) {}
    Magician(const Magician& other) : Hero(other), mana(other.mana) {}
    Magician& operator=(const Magician& other) {
        if (this != &other) {
            Hero::operator=(other);
            mana = other.mana;
        }

        return *this;
    }
    ~ Magician() {}

    Hero* clone() const override {
        return new Magician(*this);
    }

    int getHealth() const {
        return health;
    }

    int getMana() const {
        return mana;
    }

    void getInfo() const override {
        Hero::getInfo();
        std::cout << " mana: " << mana << std::endl;
    }

    void attack(Hero* enemy) override {
        enemy->setHealth(enemy->getHealth() - mana);
        mana -= 20;
    }

};