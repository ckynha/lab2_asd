#include <iostream>
#include <fstream>
#include "Knapsack.h"

void Knapsack::ReadFile(string name)
{
    ifstream input(name);
    int n; // общее число предметов
    input >> n >> maxWeight;
    for (int i = 0; i < n; ++i)
    {
        Item item;
        input >> item.name >> item.weight >> item.price;
        items.push_back(item);
    }
    input.close();
}

void Knapsack::PrintItems()
{
    for (int i = 0; i < currentItems.size(); ++i)
    {
        if (currentItems[i] != 0)
        {
            cout << items[i].name << " ";
        }
    }
    cout << "Weight: " << GetWeight() << " Price: " << GetPrice() << endl;
}

void Knapsack::Add(int startIdx)
{
    if (startIdx >= items.size()) // проверяем не закончились ли предметы
    {
        double price = GetPrice();
        if (price > maxPrice) // проверяем текущий набор на лучшую стоимость
        {
            maxPrice = price;
            bestItems = currentItems;
            bestWeight = GetWeight();
        }
        if (printFlag)
        {
            PrintItems();
        }
        return;
    }

    int w_current = GetWeight();
    if (w_current + items[startIdx].weight <= maxWeight) // проверяем можем ли добавить текущий предмет в рюкзак
    {
        currentItems[startIdx] = 1; // указываем что предмет с этим индексом находится в рюкзаке
        Add(startIdx + 1); // вызываем рекурсивно, чтобы проверить возможность добавления предмета с индексом startIdx 
        currentItems[startIdx] = 0; // исследуем возможность не добавлять предмет в рюкзак
    }
    Add(startIdx + 1);
}

void Knapsack::SearchMaxPrice()
{
    maxPrice = 0;
    currentItems.assign(items.size(), 0);
    Add(0);
}

int Knapsack::GetWeight()
{
    int weight = 0;
    for (int i = 0; i < currentItems.size(); ++i)
    {
        if (currentItems[i] != 0)
        {
            weight += items[i].weight;
        }
    }
    return weight;
}

double Knapsack::GetPrice()
{
    double price = 0;
    for (int i = 0; i < currentItems.size(); ++i)
    {
        if (currentItems[i] != 0)
        {
            price += items[i].price;
        }
    }
    return price;
}

void Knapsack::SetPrintFlag(bool flag)
{
    printFlag = flag;
}

void Knapsack::PrintBestItems() // функция для печати лучшего набора
{
    cout << "Best items: ";
    for (int i = 0; i < bestItems.size(); ++i)
    {
        if (bestItems[i] != 0)
        {
            cout << items[i].name << " ";
        }
    }
    cout << "Weight: " << bestWeight << " Price: " << maxPrice << endl;
}