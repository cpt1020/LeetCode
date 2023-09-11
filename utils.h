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
    cout << "[";
    for (int i {0}; i < vec.size(); ++i) {
        cout << "[";
        for (int j {0}; j < vec.at(i).size(); ++j) {
            cout << vec.at(i).at(j) << ((j == vec.at(i).size() - 1) ? "]" : ",");
        }
        cout << ((i == vec.size() - 1) ? "]" : ",");
    }
    
    cout << endl;
}

#endif