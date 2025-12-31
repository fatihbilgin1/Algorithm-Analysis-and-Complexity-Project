# 🚀 Algoritma Analizi ve Karmaşıklığı Projesi

Bu proje, **Algoritma Analizi ve Karmaşıklığı** dersi kapsamında hazırlanmış kapsamlı bir C++ uygulamasıdır. Proje, temel algoritma paradigmalarını (Brute Force, Divide and Conquer, Greedy, DP) incelemek, implemente etmek ve performanslarını (zaman karmaşıklığı/çağrı sayısı) analiz etmek amacıyla geliştirilmiştir.

## 👨‍💻 Proje Sahibi
**Ad Soyad:** Fatih Bilgin  
**Ders:** Algoritma Analizi ve Karmaşıklığı  
**Dil:** C++ (C++11 ve üzeri)

---

## 📂 Proje İçeriği

Proje 7 ana bölümden oluşmaktadır. Her bölüm modüler bir yapıda (`.h` dosyaları) tasarlanmış ve `main.cpp` üzerinden yönetilmektedir.

### 1️⃣ Maximum Subsequence Sum Problemi
Bir dizinin ardışık elemanlarının maksimum toplamını bulan 4 farklı yaklaşımın analizi:
- **O(N³):** Brute Force
- **O(N²):** İyileştirilmiş Brute Force
- **O(N log N):** Divide and Conquer (Böl ve Yönet)
- **O(N):** Kadane Algoritması
*📊 Özellik:* Mikrosaniye cinsinden çalışma sürelerinin karşılaştırılması.

### 2️⃣ Rekürsif (Özyinelemeli) Algoritmalar
Çeşitli problemlerin rekürsif çözümleri ve **çağrı sayısı (recursion depth)** analizi:
- 1'den N'e Toplam, Dizi Toplamı, Üs Alma
- Fibonacci Serisi
- Tower of Hanoi (Hanoi Kuleleri)
- Recursive Digit Sum

### 3️⃣ Arama Algoritmaları (Search)
Veri setleri üzerinde arama performansı:
- İleri ve Geri Yönlü Lineer Arama (Linear Search)
- İkili Arama (Binary Search - Sıralı Dizilerde)

### 4️⃣ Sıralama Algoritmaları (Sorting)
Farklı karmaşıklık sınıflarındaki algoritmaların süre karşılaştırması:
- **O(N²):** Selection Sort, Bubble Sort, Insertion Sort
- **O(N log N):** Merge Sort, Quick Sort, Heap Sort
- **Lineer:** Radix Sort

### 5️⃣ Heap Veri Yapıları
Kendi yazdığım `BinaryHeap` sınıfı ile Min-Heap işlemleri:
- `insert`, `deleteMin`, `findMin`
- `decreaseKey`, `increaseKey`, `deleteKey`
- `BuildHeap` ve `Merge` işlemleri

### 6️⃣ Greedy (Açgözlü) Algoritmalar
- **Activity Selection:** Bitiş zamanına göre en fazla aktiviteyi seçme.
- **Job Scheduling:** En kısa iş önce (SJF) mantığıyla ortalama süreyi minimize etme.
- **Huffman Coding:** Metin sıkıştırma, ağaç oluşturma ve decode işlemleri.

### 7️⃣ Dinamik Programlama (DP)
Problemlerin **tablo (matrix)** kullanılarak çözülmesi ve görselleştirilmesi:
- **Fibonacci (Bottom-Up):** Çözüm tablosu ile.
- **Minimum Cost Path (Top-Down):** Memoization tablosu gösterimi.
- **0/1 Knapsack (Sırt Çantası):** Bottom-Up yaklaşımı ve kazanç tablosu.

---

## 🛠️ Kurulum ve Çalıştırma

Projeyi kendi bilgisayarınızda çalıştırmak için bir C++ derleyicisine (G++, MinGW, Clang vb.) ihtiyacınız vardır.

### 1. Projeyi Klonlayın veya İndirin
```bash
git clone [https://github.com/KULLANICI_ADINIZ/Algoritma-Analizi-Projesi.git](https://github.com/KULLANICI_ADINIZ/Algoritma-Analizi-Projesi.git)
cd Algoritma-Analizi-Projesi
