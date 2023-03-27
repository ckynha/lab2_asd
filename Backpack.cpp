#include <iostream>
#include <fstream>
#include "Backpack.h"

void Backpack::solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            // Для каждой комбинации предметов и вместимости функция вычисляет максимальное значение, которое можно получить, используя либо i-й предмет, либо рюкзак с максимальной вместимостью
            if (j >= w[i]) { //  i-го предмета и рюкзака вместимостью j-w[i]
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]); // максимальная стоимость предметов которые могут быть помещены в рюкзак емкостью j среди первых i предметов 
            }
            else { // первых i-1 предметов и рюкзака вместимостью j 
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    double res = dp[n][W];
    int cur_w = W;
    for (int i = n; i >= 1; --i) {
        if (res == dp[i - 1][cur_w]) continue; // проверяем не приводит ли включение i-го элемента в решение к большему значению, чем значение, полученное без него  
        ans_c.push_back(c[i]);
        res -= c[i];
        cur_w -= w[i];
    }
    reverse(ans_c.begin(), ans_c.end()); // меняем порядок элементов чтобы получить решение в правильном порядке
}

void Backpack::print() {
    cout << "Best items: ";
    double total_c = 0.0;
    int total_w = 0;
    for (int i = 1; i <= n; ++i) {
        if (find(ans_c.begin(), ans_c.end(), c[i]) != ans_c.end()) {
            cout << names[i] << " ";
            total_c += c[i];
            total_w += w[i];
        }
    }
    maxPrice = total_c;
    cout << "Weight: " << total_w << " Price: " << total_c << endl;
}