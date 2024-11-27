#include "BST.h"
#include <chrono>
#include <cmath>
#include <cstring>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace std::chrono;

class MyData {
  private:
    int a, b;

  public:
    MyData(int a = 0, int b = 0) : a(a), b(b) {}
    bool operator<(const MyData& rhs) const {
        return a < rhs.a || a == rhs.a && b < rhs.b;
    }
    bool operator>(const MyData& rhs) const {
        return a > rhs.a || a == rhs.a && b > rhs.b;
    }
    bool operator==(const MyData& rhs) const {
        return a == rhs.a && b == rhs.b;
    }

    static bool checkCopy;

    MyData(const MyData& rhs) : a(rhs.a), b(rhs.b) {
        if (checkCopy) cerr << "Warning: element copy happened!" << endl;
    }
    MyData& operator=(const MyData& rhs) {
        a = rhs.a;
        b = rhs.b;
        if (checkCopy) cerr << "Warning: element copy happened!" << endl;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const MyData& rhs) {
        out << "(" << rhs.a << "," << rhs.b << ")";
        return out;
    }
};

bool MyData::checkCopy = false;

class Checker : public BinarySearchTree<int> {
  private:
    using BinarySearchTree<int>::root;
    using node = BinarySearchTree<int>::BinaryNode;

  public:
    void createChain(int N) {
        root = new node(1, nullptr, nullptr);
        root->height = N;
        auto p = root;
        for (int i = 2; i <= N; i++) {
            p->right = new node(i, nullptr, nullptr);
            p = p->right;
            p->height = N - i + 1;
        }
    }
};

void testRandomData() {
    const int N = 100;
    vector<MyData> data;
    mt19937 rnd(19260817);
    BinarySearchTree<MyData> bst;

    // Measure time for insertion
    auto startInsert = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        data.emplace_back(rnd(), rnd());
        bst.insert(data[i]);
    }
    auto endInsert = high_resolution_clock::now();
    auto durationInsert = duration_cast<milliseconds>(endInsert - startInsert);
    cout << "Time for inserting " << N << " elements: " << durationInsert.count() << " milliseconds" << endl;

    MyData::checkCopy = true;

    // Measure time for removal
    auto startRemove = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        bst.remove(data[i]);
        if (i % 20 == 0) bst.printTree();
    }
    auto endRemove = high_resolution_clock::now();
    auto durationRemove = duration_cast<milliseconds>(endRemove - startRemove);
    cout << "Time for removing " << N << " elements: " << durationRemove.count() << " milliseconds" << endl;

    bst.printTree();
}

void testIncreasingData() {
    cout << "------------------------------" << endl;
    const int N = 300000;
    Checker bst;

    // Measure time for creating a chain
    auto startCreateChain = high_resolution_clock::now();
    bst.createChain(N);
    auto endCreateChain = high_resolution_clock::now();
    auto durationCreateChain = duration_cast<milliseconds>(endCreateChain - startCreateChain);
    cout << "Time for creating a chain of size " << N << ": " << durationCreateChain.count() << " milliseconds" << endl;

    // Measure time for removal
    auto startRemoveChain = high_resolution_clock::now();
    for (int i = N; i >= 1; i--)
        bst.remove(i);
    auto endRemoveChain = high_resolution_clock::now();
    auto durationRemoveChain = duration_cast<milliseconds>(endRemoveChain - startRemoveChain);
    cout << "Time for removing " << N << " elements from chain: " << durationRemoveChain.count() << " milliseconds" << endl;

    bst.printTree();
}

int main() {
    auto start = high_resolution_clock::now();

    testRandomData();

    testIncreasingData();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Total execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
