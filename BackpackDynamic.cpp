#include <iostream>
#include <fstream>
#include "BackpackDynamic.h"

void BackpackDynamic::solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            for (int k = 0; k <= K && k <= j / w[i]; ++k) // перебирает возможное количество копий i-го предмета от 0 до K или пока не будет достигнуто максимальное количество копий, 
                                                          // которое может поместитьс€ в рюкзак (k <= j/w[i]).
            // ƒл€ каждой комбинации предмета, вместимости и количества копий функци€ вычисл€ет максимальное значение, которое можно получить, использу€ либо:
            // i-го предмета и рюкзака вместимостью j-k*w[i] (если k*w[i] <= j), либо
            // первых i - 1 предметов и того же рюкзака вместимостью j(если k * w[i] > j).
            {
                if (dp[i][j] < dp[i - 1][j - k * w[i]] + k * c[i]) {
                    dp[i][j] = dp[i - 1][j - k * w[i]] + k * c[i];
                    prev[i][j] = k;
                }
            }
        }
    }

    int cur_w = W;
    for (int i = n; i >= 1; --i) {
        int cnt = prev[i][cur_w]; // извлекаем количество копий i-го элемента 
        while (cnt--) ans.push_back(i); // добавл€ем это количество копий i-го элемента к решению ans
        cur_w -= prev[i][cur_w] * w[i]; // обновл€ем вместимость рюкзака путем вычитани€ веса выбранных копий i-го элемента
    }
    reverse(ans.begin(), ans.end());
}

void BackpackDynamic::print() {
    cout << "Best set of items: ";
    for (auto x : ans) cout << names[x] << " ";

    double total_c = 0.0;
    int total_w = 0;
    for (auto x : ans) {
        total_c += c[x];
        total_w += w[x];
    }
    cout << "Total weight: " << total_w << " Total cost: " << total_c << endl;
}