#ifndef SORU2_H
#define SORU2_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ---------------------------------------------------------
// 1. 1'den N'e Kadar Toplam (1 + 2 + ... + N)
// ---------------------------------------------------------
int sumRec(int n, int &sayac)
{
    sayac++;
    if (n <= 0)
        return 0;
    return n + sumRec(n - 1, sayac);
}

// ---------------------------------------------------------
// 2. Dizi Elemanları Toplamı
// ---------------------------------------------------------
int Sum(int A[], int N, int &sayac)
{
    sayac++;
    if (N <= 0)
        return 0;
    return Sum(A, N - 1, sayac) + A[N - 1];
}

// ---------------------------------------------------------
// 3. Üs Alma (a^n)
// ---------------------------------------------------------
long long Power(int a, int n, int &sayac)
{
    sayac++;
    if (n == 0)
        return 1;
    return a * Power(a, n - 1, sayac);
}

// ---------------------------------------------------------
// 4. Fibonacci Serisi
// ---------------------------------------------------------
int fibRec(int n, int &sayac)
{
    sayac++;
    if (n <= 1)
        return n;
    return fibRec(n - 1, sayac) + fibRec(n - 2, sayac);
}

// ---------------------------------------------------------
// 5. Tower of Hanoi
// ---------------------------------------------------------
void hanoiRec(int n, char kaynak, char hedef, char yedek, int &sayac)
{
    sayac++;
    if (n == 1)
    {
        return;
    }
    hanoiRec(n - 1, kaynak, yedek, hedef, sayac);
    hanoiRec(n - 1, yedek, hedef, kaynak, sayac);
}

// ---------------------------------------------------------
// 6. Recursive Digit Sum (Basamak Toplamı)
// ---------------------------------------------------------
int digitSumRec(int n, int &sayac)
{
    sayac++;
    if (n == 0)
        return 0;
    return (n % 10) + digitSumRec(n / 10, sayac);
}

// ---------------------------------------------------------
// TEST FONKSİYONU
// ---------------------------------------------------------
void testRecursive()
{
    cout << "\n--- 2. REKURSIF ALGORITMALAR TESTI ---\n";

    int sayac = 0;
    int n = 10;

    // 1. Toplam Testi (sumRec)
    sayac = 0;
    cout << "1. 1'den " << n << "'e Toplam: " << sumRec(n, sayac);
    cout << " | Cagri Sayisi: " << sayac << endl;

    // 2. Dizi Toplam Testi (Sum)
    sayac = 0;
    vector<int> vec = {1, 2, 3, 4, 5, 10, 20};
    cout << "2. Dizi Toplami: " << Sum(vec.data(), vec.size(), sayac);
    cout << " | Cagri Sayisi: " << sayac << endl;

    // 3. Üs Alma Testi (Power)
    sayac = 0;
    int taban = 2, us = 10;
    cout << "3. Us Alma (2^10): " << Power(taban, us, sayac);
    cout << " | Cagri Sayisi: " << sayac << endl;

    // 4. Fibonacci Testi
    sayac = 0;
    int fibN = 10;
    cout << "4. Fibonacci(" << fibN << "): " << fibRec(fibN, sayac);
    cout << " | Cagri Sayisi: " << sayac << endl;

    // 5. Hanoi Testi
    sayac = 0;
    int disk = 3;
    hanoiRec(disk, 'A', 'C', 'B', sayac);
    cout << "5. Hanoi (" << disk << " disk): (Islem yapildi)";
    cout << " | Cagri Sayisi: " << sayac << endl;

    // 6. Basamak Toplamı
    sayac = 0;
    int sayi = 9875;
    cout << "6. Basamak Toplami (" << sayi << "): " << digitSumRec(sayi, sayac);
    cout << " | Cagri Sayisi: " << sayac << endl;
}

#endif