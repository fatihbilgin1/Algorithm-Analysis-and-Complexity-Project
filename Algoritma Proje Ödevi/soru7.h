#ifndef SORU7_H
#define SORU7_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>

using namespace std;

// =============================================================
// YARDIMCI: TABLO YAZDIRMA
// =============================================================
void printTable(const vector<vector<int>> &table, const string &title)
{
    cout << "\n--- " << title << " Tablosu ---\n";
    for (const auto &row : table)
    {
        for (int val : row)
        {
            if (val == -1)
                cout << setw(5) << "-";
            else
                cout << setw(5) << val;
        }
        cout << endl;
    }
    cout << endl;
}

// =============================================================
// 1. FIBONACCI (BOTTOM-UP DP)
// =============================================================

int fibBottomUp(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 0;

    vector<int> SolTable(n + 1);

    SolTable[0] = 0;
    SolTable[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        SolTable[i] = SolTable[i - 1] + SolTable[i - 2];
    }

    cout << "\n--- Fibonacci Tablosu (SolTable) ---\n";
    cout << "Index: ";
    for (int i = 0; i <= n; i++)
        cout << setw(4) << i;
    cout << "\nValue: ";
    for (int i = 0; i <= n; i++)
        cout << setw(4) << SolTable[i];
    cout << "\n";

    return SolTable[n];
}

// =============================================================
// 2. MINIMUM COST PATH (TOP-DOWN + MEMOIZATION)
// =============================================================

int minCostRec(const vector<vector<int>> &M, int i, int j, int N, vector<vector<int>> &memo)
{

    if (i == N - 1 && j == N - 1)
    {
        return M[i][j];
    }

    if (memo[i][j] != -1)
        return memo[i][j];

    int downCost = INT_MAX;
    if (i + 1 < N)
    {
        int res = minCostRec(M, i + 1, j, N, memo);
        if (res != INT_MAX)
            downCost = res;
    }

    int rightCost = INT_MAX;
    if (j + 1 < N)
    {
        int res = minCostRec(M, i, j + 1, N, memo);
        if (res != INT_MAX)
            rightCost = res;
    }

    int minNext = min(downCost, rightCost);

    if (minNext == INT_MAX)
    {
        return memo[i][j] = INT_MAX;
    }

    return memo[i][j] = M[i][j] + minNext;
}

void minCostPath(const vector<vector<int>> &cost)
{
    int N = cost.size();

    vector<vector<int>> memo(N, vector<int>(N, -1));

    cout << "\n--- Minimum Cost Path (Maliyet Matrisi) ---\n";
    for (const auto &r : cost)
    {
        for (int v : r)
            cout << setw(5) << v;
        cout << endl;
    }

    int result = minCostRec(cost, 0, 0, N, memo);

    printTable(memo, "Hesaplanan Maliyetler (Memoization)");

    cout << "Minimum Maliyet (0,0 -> " << N - 1 << "," << N - 1 << "): " << result << endl;
}

// =============================================================
// 3. 0/1 KNAPSACK PROBLEM (SIRT ÇANTASI) - BOTTOM UP
// =============================================================

void knapsackDP(int W, const vector<int> &wt, const vector<int> &val, int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {

            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }

            else if (wt[i - 1] <= w)
            {

                int take_val = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int leave_val = dp[i - 1][w];
                dp[i][w] = max(take_val, leave_val);
            }
            else
            {

                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printTable(dp, "Knapsack (Sirt Cantasi)");

    cout << "Maksimum Kazanc: " << dp[n][W] << endl;
}

// =============================================================
// TEST FONKSİYONU
// =============================================================
void testDP()
{
    cout << "\n--- 7. DINAMIK PROGRAMLAMA TESTI ---\n";

    cout << "\n[1] Bottom-Up DP (Fibonacci)\n";
    fibBottomUp(7);

    cout << "\n[2] Min Cost Path (Top-Down Memoization)\n";

    vector<vector<int>> cost = {
        {1, 3, 1, 5},
        {2, 1, 4, 2},
        {5, 2, 1, 1},
        {3, 4, 2, 2}};
    minCostPath(cost);

    cout << "\n[3] 0/1 Knapsack Problem\n";
    vector<int> val = {30, 20, 100, 90, 160};
    vector<int> wt = {5, 10, 20, 30, 40};
    int W = 60;
    int n = val.size();

    cout << "Kapasite: " << W << "\nEsyalar (Agirlik, Deger): ";
    for (int i = 0; i < n; i++)
        cout << "(" << wt[i] << "," << val[i] << ") ";
    cout << endl;

    knapsackDP(W, wt, val, n);
}

#endif