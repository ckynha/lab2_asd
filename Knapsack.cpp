#include <iostream>
#include <fstream>
#include "Knapsack.h"

void Knapsack::ReadFile(string name)
{
    ifstream input(name);
    int n; // ����� ����� ���������
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
    if (startIdx >= items.size()) // ��������� �� ����������� �� ��������
    {
        double price = GetPrice();
        if (price > maxPrice) // ��������� ������� ����� �� ������ ���������
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
    if (w_current + items[startIdx].weight <= maxWeight) // ��������� ����� �� �������� ������� ������� � ������
    {
        currentItems[startIdx] = 1; // ��������� ��� ������� � ���� �������� ��������� � �������
        Add(startIdx + 1); // �������� ����������, ����� ��������� ����������� ���������� �������� � �������� startIdx 
        currentItems[startIdx] = 0; // ��������� ����������� �� ��������� ������� � ������
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

void Knapsack::PrintBestItems() // ������� ��� ������ ������� ������
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