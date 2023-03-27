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

void print2dVector(const vector<vector<int>> & vec){
    for (auto & row: vec){
        for (auto & num: row){
            cout << num << " ";
        }
        cout << endl;
    }
}