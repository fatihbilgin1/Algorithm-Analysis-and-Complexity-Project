#ifndef SORU5_H
#define SORU5_H

#include <iostream>
#include <vector>
#include <climits>
#include <stdexcept>
#include <algorithm>

using namespace std;

// =============================================================
// BINARY HEAP SINIFI (MIN HEAP)
// =============================================================
class BinaryHeap
{
public:
    BinaryHeap(int capacity = 100)
    {
        array.resize(capacity + 1);
        array[0] = INT_MIN;
        currentSize = 0;
    }

    BinaryHeap(const vector<int> &items) : array(items.size() + 10), currentSize(items.size())
    {
        array[0] = INT_MIN;
        for (int i = 0; i < items.size(); ++i)
            array[i + 1] = items[i];
        buildHeap();
    }

    bool isEmpty() const
    {
        return currentSize == 0;
    }

    // --- 1. FIND MIN ---
    const int &findMin() const
    {
        if (isEmpty())
            throw underflow_error("Heap bos!");
        return array[1];
    }

    // --- 2. INSERT (Ekleme) ---

    void insertHeap(const int &key)
    {
        if (currentSize == array.size() - 1)
            array.resize(array.size() * 2);

        currentSize++;

        int node = currentSize;
        array[node] = key;

        while (node > 1)
        {
            int parent = node / 2;

            if (array[parent] <= array[node])
                break;

            int tmp = array[node];
            array[node] = array[parent];
            array[parent] = tmp;

            node = parent;
        }
    }

    // --- 3. DELETE MIN (Silme) ---
    void deleteMin()
    {
        if (isEmpty())
            throw underflow_error("Heap bos!");

        array[1] = array[currentSize];
        currentSize--;

        if (currentSize > 0)
            percolateDown(1);
    }

    void deleteMin(int &minItem)
    {
        if (isEmpty())
            throw underflow_error("Heap bos!");
        minItem = array[1];
        deleteMin();
    }

    // --- 4. BUILD HEAP ---
    void buildHeap()
    {
        for (int i = currentSize / 2; i > 0; i--)
            percolateDown(i);
    }

    void buildMaxHeap()
    {
        for (int i = currentSize / 2; i > 0; i--)
            percolateDownMax(i);
    }

    // --- 5. DECREASE KEY ---
    void decreaseKey(int pos, int delta)
    {
        if (pos > currentSize || pos < 1)
            return;

        array[pos] -= delta;

        int node = pos;
        while (node > 1 && array[node] < array[node / 2])
        {
            swap(array[node], array[node / 2]);
            node /= 2;
        }
    }

    // --- 6. INCREASE KEY ---
    void increaseKey(int pos, int delta)
    {
        if (pos > currentSize || pos < 1)
            return;
        array[pos] += delta;
        percolateDown(pos);
    }

    // --- 7. DELETE KEY ---
    void deleteKey(int pos)
    {
        if (pos > currentSize || pos < 1)
            return;
        decreaseKey(pos, INT_MAX - 100);
        deleteMin();
    }

    // --- 8. MERGE ---
    void Merge(BinaryHeap &other)
    {
        for (int i = 1; i <= other.currentSize; i++)
        {
            this->insertHeap(other.array[i]);
        }
        other.currentSize = 0;
    }

    // Yazdırma
    void printHeap()
    {
        for (int i = 1; i <= currentSize; i++)
            cout << array[i] << " ";
        cout << endl;
    }

private:
    vector<int> array;
    int currentSize;

    void percolateDown(int node)
    {
        int child;
        int tmp = array[node];

        while (node * 2 <= currentSize)
        {
            child = node * 2;

            if (child != currentSize && array[child + 1] < array[child])
                child++;

            if (array[child] < tmp)
                array[node] = array[child];
            else
                break;

            node = child;
        }
        array[node] = tmp;
    }

    void percolateDownMax(int node)
    {
        int child;
        int tmp = array[node];
        while (node * 2 <= currentSize)
        {
            child = node * 2;
            if (child != currentSize && array[child + 1] > array[child])
                child++;
            if (array[child] > tmp)
                array[node] = array[child];
            else
                break;
            node = child;
        }
        array[node] = tmp;
    }
};

// =============================================================
// TEST FONKSİYONU
// =============================================================
void testHeap()
{
    cout << "\n--- 5. HEAP YAPILARI TESTI ---\n";

    BinaryHeap h;

    h.insertHeap(10);
    h.insertHeap(5);
    h.insertHeap(20);
    h.insertHeap(3);

    cout << "Heap (Insert sonrasi): ";
    h.printHeap();

    cout << "Min Eleman: " << h.findMin() << endl;

    h.deleteMin();
    cout << "DeleteMin sonrasi: ";
    h.printHeap();

    cout << "DecreaseKey (3. eleman, delta=18): ";
    h.decreaseKey(3, 18);
    h.printHeap();

    vector<int> veri = {50, 30, 40, 10, 5, 20};
    BinaryHeap h2(veri);
    cout << "\nBuildHeap (MinHeap) sonucu: ";
    h2.printHeap();

    cout << "\nMerge islemi...\n";
    h.Merge(h2);
    h.printHeap();
}

#endif