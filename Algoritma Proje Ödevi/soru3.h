#ifndef SORU3_H
#define SORU3_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ---------------------------------------------------------
// 1. İLERİ YÖNLÜ LİNEER ARAMA (Forward Linear Search)
// ---------------------------------------------------------
int LinearSearch(int A[], int N, int key)
{
    int i = 0;
    while (i < N)
    {
        if (A[i] == key)
            return i;
        i++;
    }
    return -1;
}

// ---------------------------------------------------------
// 2. GERİ YÖNLÜ LİNEER ARAMA (Backward Linear Search)
// ---------------------------------------------------------
int LinearSearchBackward(int A[], int N, int key)
{
    for (int i = N - 1; i >= 0; i--)
    {
        if (A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// ---------------------------------------------------------
// 3. İKİLİ ARAMA (Binary Search)
// ---------------------------------------------------------
int BinarySearch(int A[], int N, int key)
{

    int left = 0;
    int right = N - 1;

    while (left <= right)
    {

        int mid = left + (right - left) / 2;

        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// ---------------------------------------------------------
// TEST FONKSİYONU
// ---------------------------------------------------------
void testSearch()
{
    cout << "\n--- 3. ARAMA ALGORITMALARI TESTI ---\n";

    int n = 20;
    vector<int> veri(n);

    cout << "Veri Seti: ";
    for (int i = 0; i < n; i++)
    {
        veri[i] = i * 2;
        cout << veri[i] << " ";
    }
    cout << endl;

    int aranan = 14;
    int olmayan = 99;

    cout << "\nAranan Sayi: " << aranan << endl;

    int sonuc = LinearSearch(veri.data(), n, aranan);
    cout << "1. Ileri Yonlu Arama: ";
    if (sonuc != -1)
        cout << "Bulundu (Indis: " << sonuc << ")\n";
    else
        cout << "Bulunamadi\n";

    sonuc = LinearSearchBackward(veri.data(), n, aranan);
    cout << "2. Geri Yonlu Arama:  ";
    if (sonuc != -1)
        cout << "Bulundu (Indis: " << sonuc << ")\n";
    else
        cout << "Bulunamadi\n";

    sonuc = BinarySearch(veri.data(), n, aranan);
    cout << "3. Ikili Arama (Binary): ";
    if (sonuc != -1)
        cout << "Bulundu (Indis: " << sonuc << ")\n";
    else
        cout << "Bulunamadi\n";

    cout << "\nOlmayan Sayi Testi (" << olmayan << "): ";

    if (BinarySearch(veri.data(), n, olmayan) == -1)
        cout << "Basariyla BULUNAMADI dondu.\n";
    else
        cout << "HATA! Olmayan sayiyi buldu.\n";
}

#endif