#ifndef SORU4_H
#define SORU4_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define SWAP(x, y) \
    {              \
        int t = x; \
        x = y;     \
        y = t;     \
    }

// =============================================================
// 1. BASİT SIRALAMA ALGORİTMALARI (O(N^2))
// =============================================================

// --- SELECTION SORT ---
void selectionSortArr(int A[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }
        if (i != minIndex)
            SWAP(A[i], A[minIndex]);
    }
}

// --- BUBBLE SORT ---
void bubbleSortArr(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < (N - i); j++)
        {
            if (A[j - 1] > A[j])
            {
                SWAP(A[j - 1], A[j]);
            }
        }
    }
}

// --- INSERTION SORT ---
void insertionSortArr(int A[], int N)
{
    int j, P, Tmp;
    for (P = 1; P < N; P++)
    {
        Tmp = A[P];
        for (j = P; j > 0 && Tmp < A[j - 1]; j--)
            A[j] = A[j - 1];
        A[j] = Tmp;
    }
}

// =============================================================
// 2. VERİMLİ SIRALAMA ALGORİTMALARI (O(N log N))
// =============================================================

void Merge(int A[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    int size = right - left + 1;
    vector<int> Temp(size);

    while (i <= mid && j <= right)
    {
        if (A[i] <= A[j])
            Temp[k++] = A[i++];
        else
            Temp[k++] = A[j++];
    }
    while (i <= mid)
        Temp[k++] = A[i++];
    while (j <= right)
        Temp[k++] = A[j++];

    for (k = 0; k < size; k++)
        A[left + k] = Temp[k];
}

// --- MERGE SORT (Recursive) ---
void MS(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MS(A, left, mid);
        MS(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}

// --- QUICK SORT (Yardımcı: Partition) ---
int Partition(int A[], int left, int right)
{
    int pivot = A[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            SWAP(A[i], A[j]);
        }
    }
    SWAP(A[i + 1], A[right]);
    return (i + 1);
}

// --- QUICK SORT (Recursive) ---
void QS(int A[], int left, int right)
{
    if (left < right)
    {
        int pi = Partition(A, left, right);
        QS(A, left, pi - 1);
        QS(A, pi + 1, right);
    }
}

// --- HEAP SORT ---
void percDown(vector<int> &a, int i, int n)
{
    int child;
    int tmp;
    for (tmp = a[i]; 2 * i + 1 < n; i = child)
    {
        child = 2 * i + 1;
        if (child != n - 1 && a[child + 1] > a[child])
            child++;
        if (tmp < a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = tmp;
}

void heapSort(vector<int> &a)
{
    for (int i = a.size() / 2 - 1; i >= 0; i--)
        percDown(a, i, a.size());
    for (int j = a.size() - 1; j > 0; j--)
    {
        int temp = a[0];
        a[0] = a[j];
        a[j] = temp;
        percDown(a, 0, j);
    }
}

// =============================================================
// 3. RADIX SORT
// =============================================================
int getMax(const vector<int> &a)
{
    int mx = a[0];
    for (size_t i = 1; i < a.size(); i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}

void countSortForRadix(vector<int> &a, int exp)
{
    int n = a.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(vector<int> &a)
{
    int m = getMax(a);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortForRadix(a, exp);
}

// =============================================================
// 4. TEST İÇİN SARMALAYICI (WRAPPER) FONKSİYONLAR
// =============================================================

void selectionSortWrapper(vector<int> &a) { selectionSortArr(a.data(), a.size()); }
void bubbleSortWrapper(vector<int> &a) { bubbleSortArr(a.data(), a.size()); }
void insertionSortWrapper(vector<int> &a) { insertionSortArr(a.data(), a.size()); }
void mergeSortWrapper(vector<int> &a) { MS(a.data(), 0, a.size() - 1); }
void quickSortWrapper(vector<int> &a) { QS(a.data(), 0, a.size() - 1); }

// =============================================================
// TEST FONKSİYONU
// =============================================================

void testSorting()
{
    cout << "\n--- 4. SIRALAMA ALGORITMALARI TESTI ---\n";

    int n;
    cout << "Dizi boyutunu girin (Orn: 2000, 10000): ";
    cin >> n;

    vector<int> orjinalVeri(n);
    srand(time(0));
    for (int i = 0; i < n; i++)
        orjinalVeri[i] = rand() % 10000;

    auto testAlgo = [&](string isim, void (*func)(vector<int> &))
    {
        vector<int> veri = orjinalVeri;
        auto start = high_resolution_clock::now();
        func(veri);
        auto end = high_resolution_clock::now();
        auto sure = duration_cast<microseconds>(end - start).count();
        cout << isim << " Sure: " << sure << " us" << endl;
    };

    cout << "--- O(N^2) Algoritmalar ---\n";
    testAlgo("Selection Sort", selectionSortWrapper);
    testAlgo("Bubble Sort   ", bubbleSortWrapper);
    testAlgo("Insertion Sort", insertionSortWrapper);

    cout << "\n--- O(N log N) Algoritmalar ---\n";
    testAlgo("Merge Sort    ", mergeSortWrapper);
    testAlgo("Quick Sort    ", quickSortWrapper);
    testAlgo("Heap Sort     ", heapSort);

    cout << "\n--- Linear Sort ---\n";
    testAlgo("Radix Sort    ", radixSort);
}

#endif