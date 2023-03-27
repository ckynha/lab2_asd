#pragma once
#include <vector>

using namespace std;

class Backpack
{
private:
    int n;
    int W;
    int maxPrice;
    vector<int> w; // ������ ����� ���������
    vector<double> c; // ������ ����������� ���������
    vector<vector<double>> dp; // ��������� ������ ������� (n+1) x (W+1), 
                               // ��� dp[i][j] ������������ ����� ������������ ��������, 
                               // ������� ����� ��������, ��������� ������ i ��������� � ������ � ������������ ������������ j
    vector<string> names; // ������ ���� ���������
    vector<double> ans_c;
public:
    Backpack() {
        ifstream fin("input.txt");
        fin >> n >> W;
        w.resize(n + 1);
        c.resize(n + 1);
        dp.resize(n + 1, vector<double>(W + 1));
        names.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            fin >> names[i] >> w[i] >> c[i];
        }
        fin.close();
    }
    void solve();
    void print();

    int GetMaxPrice()
    {
        return maxPrice;
    }
};