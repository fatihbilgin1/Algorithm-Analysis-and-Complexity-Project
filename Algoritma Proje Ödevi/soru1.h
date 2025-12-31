#ifndef SORU1_H
#define SORU1_H

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// ----------------------------------------------------
// 1. ALGORITMA: O(N^3) - Brute Force
// ----------------------------------------------------
int maxSubSum1(const vector<int> &a)
{
    int maxSum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            int thisSum = 0;
            for (int k = i; k <= j; k++)
            {
                thisSum += a[k];
            }
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

// ----------------------------------------------------
// 2. ALGORITMA: O(N^2)
// ----------------------------------------------------
int maxSubSum2(const vector<int> &a)
{
    int maxSum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int thisSum = 0;
        for (int j = i; j < a.size(); j++)
        {
            thisSum += a[j];
            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

// ----------------------------------------------------
// 3. ALGORITMA: O(N log N) - Divide and Conquer
// ----------------------------------------------------

int max3(int a, int b, int c) { return max(a, max(b, c)); }

int maxSubRec(const vector<int> &a, int left, int right)
{
    if (left == right)
        return (a[left] > 0) ? a[left] : 0;

    int center = (left + right) / 2;
    int maxLeftSum = maxSubRec(a, left, center);
    int maxRightSum = maxSubRec(a, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--)
    {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int i = center + 1; i <= right; i++)
    {
        rightBorderSum += a[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int maxSubSum3(const vector<int> &a)
{
    return maxSubRec(a, 0, a.size() - 1);
}

// ----------------------------------------------------
// 4. ALGORITMA: O(N) - Kadane Algoritması
// ----------------------------------------------------
int maxSubSum4(const vector<int> &a)
{
    int maxSum = 0, thisSum = 0;
    for (int j = 0; j < a.size(); j++)
    {
        thisSum += a[j];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

// ----------------------------------------------------
// TEST FONKSİYONU VE ZAMAN ÖLÇÜMÜ
// ----------------------------------------------------
void testMaxSubsequence()
{
    cout << "\n--- 1. Maximum Subsequence Testi ---\n";

    int n;
    cout << "Dizi boyutu girin (Orn: 5000): ";
    cin >> n;

    vector<int> veri(n);
    srand(time(0));
    for (int i = 0; i < n; i++)
        veri[i] = (rand() % 201) - 100;

    // Test lambda fonksiyonu
    auto olc = [](auto func, const vector<int> &v)
    {
        auto start = high_resolution_clock::now();
        func(v);
        auto end = high_resolution_clock::now();
        return duration_cast<microseconds>(end - start).count();
    };

    cout << "Veri hazir. Olcum basliyor...\n";

    cout << "1. O(N^3)   Sure: " << olc(maxSubSum1, veri) << " us\n";
    cout << "2. O(N^2)   Sure: " << olc(maxSubSum2, veri) << " us\n";
    cout << "3. O(NlogN) Sure: " << olc(maxSubSum3, veri) << " us\n";
    cout << "4. O(N)     Sure: " << olc(maxSubSum4, veri) << " us\n";
}

#endif