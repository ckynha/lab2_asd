#pragma once
#include <vector>

using namespace std;

class Item // класс для описания каждого предмета
{
public:
    string name;
    int weight;
    double price;
};

class Knapsack
{
private:
    vector<Item> items; // храненит каждый предмет
    vector<int> currentItems; // хранит текущий набор предметов
    int bestWeight; // вес при лучшей стоимости
    int maxWeight; // максимальный вес рюкзака
    double maxPrice; // максимальная стоимость рюкзака
    vector<int> bestItems; // хранит лучший набор предметов с максимальной ценностью
    bool printFlag;

    void PrintItems();
    void Add(int startIdx);
    int GetWeight();
    double GetPrice();

public:
    void ReadFile(string name);
    void SearchMaxPrice();
    void SetPrintFlag(bool flag);
    void PrintBestItems();

    int GetMaxPrice()
    {
        return maxPrice;
    }
};
