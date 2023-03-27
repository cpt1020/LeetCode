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