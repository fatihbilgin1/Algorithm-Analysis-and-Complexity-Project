#include <iostream>

#include "soru1.h"
#include "soru2.h"
#include "soru3.h"
#include "soru4.h"
#include "soru5.h"
#include "soru6.h"
#include "soru7.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Turkish");

    int secim = -1;
    while (secim != 0)
    {
        cout << "\n============================================\n";
        cout << "   ALGORITMA ANALIZI PROJE - FATIH BILGIN\n";
        cout << "============================================\n";
        cout << "1. Maximum Subsequence Problemi\n";
        cout << "2. Rekursif Algoritmalar\n";
        cout << "3. Arama Algoritmalari\n";
        cout << "4. Siralama Algoritmalari\n";
        cout << "5. Heap Yapilari (Binary Heap)\n";
        cout << "6. Greedy Algoritmalar (Huffman, Job Scheduling)\n";
        cout << "7. Dinamik Programlama (DP)\n";
        cout << "0. CIKIS\n";
        cout << "--------------------------------------------\n";
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim)
        {
        case 1:

            testMaxSubsequence();
            break;
        case 2:

            testRecursive();
            break;
        case 3:

            testSearch();
            break;
        case 4:

            testSorting();
            break;
        case 5:
            testHeap();
            break;
        case 6:
            testGreedy();
            break;
        case 7:
            testDP();
            break;
        case 0:
            cout << "Programdan cikiliyor. Iyi gunler...\n";
            break;
        default:
            cout << "Gecersiz secim! Lutfen tekrar deneyin.\n";
        }
    }

    return 0;
}