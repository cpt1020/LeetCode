#include <vector>
#include <iostream>
#include <algorithm>
#include "../utils.h"
using namespace std;

/*
g++ 435.cpp ../utils.cpp -std=c++17 -o 435
*/

bool compare(vector<int>& a, vector<int>& b){
    return a.at(1) < b.at(1);
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() == 1){
        return 0;
    }

    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a.at(1) < b.at(1);});
    // in this case, we have to do sorting according to the second element of the vector
    // [](vector<int>& a, vector<int>& b){return a.at(1) < b.at(1);} is lambda expression
    // we can also write it in the following way:
    // sort(intervals.begin(), intervals.end(), compare);

    // print2dVector(intervals);

    int ans {0};

    int prevStart {intervals.at(0).at(0)};
    int prevEnd {intervals.at(0).at(1)};

    for (int i {1}; i < intervals.size(); ++i){
        if (intervals.at(i).at(0) < prevEnd){
            ans += 1;
        }
        else {
            prevStart = intervals.at(i).at(0);
            prevEnd = intervals.at(i).at(1);
        }
    }

    return ans;
}

int main(){

    vector<vector<int>> intervals {
        {-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}
    };

    cout << eraseOverlapIntervals(intervals) << endl;

    return 0;
}