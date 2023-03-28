#include <iostream>
#include <vector>
#include <algorithm>
#include "../utils.h"
using namespace std;

/*
g++ 56.cpp ../utils.cpp -std=c++17 -o 56 && ./56
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 1){
        return intervals;
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    int prevStart {intervals.at(0).at(0)};
    int prevEnd {intervals.at(0).at(1)};

    for (int i {1}; i < intervals.size(); ++i){
        if (intervals.at(i).at(0) <= prevEnd){
            prevEnd = max(prevEnd, intervals.at(i).at(1));
        }
        else {
            ans.push_back({prevStart, prevEnd});

            prevStart = intervals.at(i).at(0);
            prevEnd = intervals.at(i).at(1);
        }
    }

    ans.push_back({prevStart, prevEnd});

    return ans;
}

int main(){

    vector<vector<int>> intervals {
        {1,3}, {2,6}, {8,10}, {15,18}
    };

    print2dVector(merge(intervals));

    return 0;
}