#pragma once
#include <vector>

using namespace std;

class Backpack
{
private:
    int n;
    int W;
    int maxPrice;
    vector<int> w; // вектор весов предметов
    vector<double> c; // вектор стоиомостей предметов
    vector<vector<double>> dp; // двумерный массив размера (n+1) x (W+1), 
                               // где dp[i][j] представл€ет собой максимальное значение, 
                               // которое можно получить, использу€ первые i предметов и рюкзак с максимальной вместимостью j
    vector<string> names; // вектор имен предметов
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