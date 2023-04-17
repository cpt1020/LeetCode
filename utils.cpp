#include "utils.h"
#include <vector>
#include <iostream>
using namespace std;

void printVector(const vector<int> & vec){
    for (auto & num: vec){
        cout << num << " ";
    }
    cout << endl;
}

void printVector(const vector<long long> & vec){
    for (auto & num: vec){
        cout << num << " ";
    }
    cout << endl;
}

void printVector(const vector<string> & vec){
    for (auto & str: vec){
        cout << str << " ";
    }
    cout << endl;
}

void printVector(const vector<bool> & vec) {
    for (bool res: vec){
        cout << boolalpha << res << " ";
    }
    cout << endl;
}

void print2dVector(const vector<vector<int>> & vec){
    for (auto & row: vec){
        for (auto & num: row){
            cout << num << " ";
        }
        cout << endl;
    }
}