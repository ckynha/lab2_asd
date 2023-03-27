#include <iostream>
#include <fstream>
#include "BackpackDynamic.h"

void BackpackDynamic::solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            for (int k = 0; k <= K && k <= j / w[i]; ++k) // ���������� ��������� ���������� ����� i-�� �������� �� 0 �� K ��� ���� �� ����� ���������� ������������ ���������� �����, 
                                                          // ������� ����� ����������� � ������ (k <= j/w[i]).
            // ��� ������ ���������� ��������, ����������� � ���������� ����� ������� ��������� ������������ ��������, ������� ����� ��������, ��������� ����:
            // i-�� �������� � ������� ������������ j-k*w[i] (���� k*w[i] <= j), ����
            // ������ i - 1 ��������� � ���� �� ������� ������������ j(���� k * w[i] > j).
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
        int cnt = prev[i][cur_w]; // ��������� ���������� ����� i-�� �������� 
        while (cnt--) ans.push_back(i); // ��������� ��� ���������� ����� i-�� �������� � ������� ans
        cur_w -= prev[i][cur_w] * w[i]; // ��������� ����������� ������� ����� ��������� ���� ��������� ����� i-�� ��������
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