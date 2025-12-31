#ifndef SORU6_H
#define SORU6_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>

using namespace std;

// =============================================================
// 1. AKTİVİTE SEÇİMİ (ACTIVITY SELECTION) PROBLEMI
// =============================================================

struct Activity
{
    int id;
    int start;
    int finish;
};

bool activityCompare(const Activity &s1, const Activity &s2)
{
    return (s1.finish < s2.finish);
}

void activitySelection(vector<Activity> &activities)
{
    if (activities.empty())
        return;

    sort(activities.begin(), activities.end(), activityCompare);

    cout << "--- Aktivite Secimi Sonuclari ---\n";
    cout << "Secilen Aktiviteler (ID): ";

    int prevIndex = 0;
    cout << activities[prevIndex].id << " ";

    for (int i = 1; i < activities.size(); i++)
    {

        if (activities[i].start >= activities[prevIndex].finish)
        {
            cout << activities[i].id << " ";
            prevIndex = i;
        }
    }
    cout << endl;
}

// =============================================================
// 2. İŞ ZAMANLAMA (JOB SCHEDULING - SHORTEST JOB FIRST)
// =============================================================

struct JobSJF
{
    string id;
    int time;
};

bool jobCompareSJF(const JobSJF &a, const JobSJF &b)
{
    return a.time < b.time;
}

void jobScheduling(vector<JobSJF> &jobs)
{

    sort(jobs.begin(), jobs.end(), jobCompareSJF);

    cout << "\n--- Is Zamanlama (En Kisa Is Once) ---\n";
    cout << "Siralama: ";

    int currentTime = 0;
    double totalCompletionTime = 0;

    for (const auto &job : jobs)
    {
        cout << job.id << "(" << job.time << ") ";

        currentTime += job.time;
        totalCompletionTime += currentTime;
    }

    cout << "\nToplam Tamamlanma Suresi: " << totalCompletionTime;
    cout << "\nOrtalama Tamamlanma Suresi: " << totalCompletionTime / jobs.size() << endl;
}

// =============================================================
// 3. HUFFMAN KODLAMA (HUFFMAN CODING)
// =============================================================

struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void storeCodes(struct MinHeapNode *root, string str, map<char, string> &huffmanCode)
{
    if (!root)
        return;
    if (root->data != '$')
        huffmanCode[root->data] = str;

    storeCodes(root->left, str + "0", huffmanCode);
    storeCodes(root->right, str + "1", huffmanCode);
}

map<char, string> buildHuffmanTree(const string &text, MinHeapNode *&rootRef)
{
    map<char, int> freq;
    for (char c : text)
        freq[c]++;

    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (auto pair : freq)
        minHeap.push(new MinHeapNode(pair.first, pair.second));

    while (minHeap.size() != 1)
    {
        MinHeapNode *left = minHeap.top();
        minHeap.pop();
        MinHeapNode *right = minHeap.top();
        minHeap.pop();

        MinHeapNode *top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    rootRef = minHeap.top();
    map<char, string> huffmanCode;
    storeCodes(rootRef, "", huffmanCode);
    return huffmanCode;
}

string decodeHuffman(MinHeapNode *root, string encodedStr)
{
    string ans = "";
    struct MinHeapNode *curr = root;
    for (int i = 0; i < encodedStr.size(); i++)
    {
        if (encodedStr[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;

        if (curr->left == nullptr && curr->right == nullptr)
        {
            ans += curr->data;
            curr = root;
        }
    }
    return ans;
}

// =============================================================
// TEST FONKSİYONU
// =============================================================
void testGreedy()
{
    cout << "\n--- 6. GREEDY ALGORITMALAR TESTI ---\n";

    vector<Activity> activities = {
        {1, 1, 4}, {2, 3, 5}, {3, 0, 6}, {4, 5, 7}, {5, 3, 9}, {6, 5, 9}, {7, 6, 10}, {8, 8, 11}, {9, 8, 12}, {10, 2, 14}, {11, 12, 16}};

    activitySelection(activities);

    vector<JobSJF> jobs = {
        {"J1", 15}, {"J2", 8}, {"J3", 3}, {"J4", 10}};
    jobScheduling(jobs);

    cout << "\n[3] Huffman Kodlama\n";
    string text = "algoritma analizi";
    MinHeapNode *root = nullptr;
    map<char, string> codes = buildHuffmanTree(text, root);

    cout << "Karakter Kodlari:\n";
    for (auto pair : codes)
        cout << pair.first << ":" << pair.second << " ";
    cout << endl;

    string encoded = "";
    for (char c : text)
        encoded += codes[c];
    cout << "Encoded: " << encoded << endl;
    cout << "Decoded: " << decodeHuffman(root, encoded) << endl;
}

#endif