#pragma once
#include <vector>

using namespace std;

class BackpackDynamic
{
private:
    int n;
    int W;
    int K = 1;
    vector<int> w;
    vector<double> c;
    vector<vector<double>> dp; // двумерный вектор размера (n+1) x (W+1), 
                               // где dp[i][j] представляет собой максимальное значение, 
                               // которое можно получить, используя первые i предметов и рюкзак с максимальной вместимостью j
    vector<vector<int>> prev;  // двумерный вектор размера(n + 1) x(W + 1), 
                               // где prev[i][j] представляет собой количество копий i - го предмета, взятых для достижения максимального значения dp[i][j].
    vector<string> names;
    vector<int> ans;
public:
    BackpackDynamic(int K = 1): K(K) {
        ifstream fin("input.txt");
        fin >> n >> W;
        w.resize(n + 1);
        c.resize(n + 1);
        dp.resize(n + 1, vector<double>(W + 1));
        prev.resize(n + 1, vector<int>(W + 1));
        names.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            fin >> names[i] >> w[i] >> c[i];
        }
        fin.close();
    }

    void solve();
    void print();
};
