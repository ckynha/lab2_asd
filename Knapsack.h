#pragma once
#include <vector>

using namespace std;

class Item // ����� ��� �������� ������� ��������
{
public:
    string name;
    int weight;
    double price;
};

class Knapsack
{
private:
    vector<Item> items; // �������� ������ �������
    vector<int> currentItems; // ������ ������� ����� ���������
    int bestWeight; // ��� ��� ������ ���������
    int maxWeight; // ������������ ��� �������
    double maxPrice; // ������������ ��������� �������
    vector<int> bestItems; // ������ ������ ����� ��������� � ������������ ���������
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
