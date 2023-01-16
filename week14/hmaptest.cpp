#define DOCTEST_CONFIG_IMPLEMENT
#include "./doctest.h"


#include "hmap.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>


int h1 (const std::string &key)
{
    return key.length();
}

int h2(const std::string& key) {
    int result = 0;
    for (int i = 0; i < key.length(); ++i) {
        result += std::pow(key[i], i + 1) * (i + 1);
    }

    return result;
}

TEST_CASE("Basic Test")
{
    HMap<std::string,int> phonebook(10, h1);

    phonebook["Kalin Georgiev"] = 9999;
    CHECK(phonebook["Kalin Georgiev"] == 9999);

    phonebook["Ivanka Petrova"] = 19999;
    CHECK(phonebook["Ivanka Petrova"] == 19999);
    CHECK(phonebook["Kalin Georgiev"] == 9999);

    phonebook["Kalin Georgiev"] = 29999;
    CHECK(phonebook["Kalin Georgiev"] == 29999);

}

TEST_CASE("Test Collisions")
{
    HMap<std::string,int> map(3, h1);

    std::vector<std::pair<std::string,int>> expected =
        {{"aaa",1},
         {"bbbb", 2},
         {"bbbc", 3},
         {"c",4},
         {"dd",5}};

    for(std::pair<std::string,int> p:expected)
    {
        map[p.first] = p.second;
    }   

    for(std::pair<std::string,int> p:expected)
    {
        CHECK(map[p.first] == p.second);
    }

}

void printHashMap(const HMap<std::string, std::pair<double, unsigned>>& hmap, const std::vector<std::string>& products) {

}

TEST_CASE("Shop system") {
    HMap<std::string, std::pair<double, unsigned>> shopSystem(4, h2);

    shopSystem["beer"] = std::make_pair<double, unsigned>(1.30, 50);
    shopSystem["nuts"] = std::pair<double, unsigned>(4.00, 15);
    shopSystem["beer"] = std::make_pair<double, unsigned>(1.50, 25);
    shopSystem["juice"] = std::make_pair<double, unsigned>(1.70, 20);

    std::vector<std::string> products = {"beer", "nuts", "beer", "juice"};

    for (int i = 0; i < 4; ++i) {
        std::cout << products[i] << " " << shopSystem[products[i]].first << " " << shopSystem[products[i]].second << std::endl;
    }

    double money = 150.00;
    std::vector<std::pair<std::string, unsigned>> shopingList;

    shopingList.push_back(std::make_pair<std::string, unsigned>("beer", 3));
    shopingList.push_back(std::make_pair<std::string, unsigned>("nuts", 2));
    shopingList.push_back(std::make_pair<std::string, unsigned>("juice", 25));

    for (int i = 0; i < shopingList.size(); ++i) {
        if (shopSystem[shopingList[i].first].second >= shopingList[i].second) {
            if (shopSystem[shopingList[i].first].first * shopingList[i].second <= money) {
                money -= shopSystem[shopingList[i].first].first * shopingList[i].second;
                shopSystem[shopingList[i].first].second -= shopingList[i].second;  
            }
        }
        if (shopSystem[shopingList[i].first].second < shopingList[i].second) {
            if (shopSystem[shopingList[i].first].first * shopSystem[shopingList[i].first].second <= money) {
                money -= shopSystem[shopingList[i].first].first * shopSystem[shopingList[i].first].second;
                shopSystem[shopingList[i].first].second = 0;
            }
        }
    }

    std::cout << money << std::endl;

    for (int i = 0; i < 4; ++i) {
        std::cout << products[i] << " " << shopSystem[products[i]].first << " " << shopSystem[products[i]].second << std::endl;
    }

}

int main()
{
    
    doctest::Context().run();
}