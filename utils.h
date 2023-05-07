#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <iostream>
using namespace std;

void printVector(const vector<int> & vec);
void printVector(const vector<long long> & vec);
void printVector(const vector<string> & vec);
void printVector(const vector<bool> & vec);
void print2dVector(const vector<vector<int>> & vec);

template <typename T>
void printVector(const vector<T>& vec) {
    cout << "[ ";
    for (auto val: vec) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

template <typename T>
void print2dVector(const vector<vector<T>>& vec) {
    for (auto v: vec) {
        for (auto val: v) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif