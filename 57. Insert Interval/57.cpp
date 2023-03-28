#include <vector>
#include <iostream>
#include "../utils.h"
using namespace std;

/*
g++ 57.cpp ../utils.cpp -std=c++17 -o 57 && ./57
*/

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (intervals.size() == 0){
        return {newInterval};
    }

    vector<vector<int>> result;

    int minStart {newInterval.at(0)};
    int maxEnd {newInterval.at(1)};
    bool flag1 {false};
    bool flag2 {false};

    for (auto vec: intervals){
        // 比newInterval起始點小的interval都直接push到result
        if (newInterval.at(0) > vec.at(1)){
            result.push_back(vec);
        }
        else if (newInterval.at(1) < vec.at(0)){
            if (flag1 == true && flag2 == false){
                result.push_back({minStart, maxEnd});
                flag2 = true;
            }
            // 若newInterval直接小於第一個interval
            else if (flag1 == false){
                result.push_back(newInterval);
                flag1 = flag2 = true;
            }
            result.push_back(vec);
        }
        else{
            if (flag1 == false && flag2 == false){
                minStart = min(minStart, vec.at(0));
                maxEnd = max(vec.at(1), maxEnd);
                flag1 = true;
            }
            else if (flag1 == true && flag2 == false){
                maxEnd = max(maxEnd, vec.at(1));
            }
        }
    }

    if (result.size() == 0 || flag2 == false){
        result.push_back({minStart, maxEnd});
    }

    return result;
}

vector<vector<int>> insert_v2(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (intervals.size() == 0){
        return {newInterval};
    }
    
    vector<vector<int>> ans;
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());

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
    // test case 01
    cout << "test case 01, version 1:" << endl;
    vector<vector<int>> intervals {
        {1,3}, {6,9}
    };
    vector<int> newInterval {2,5};
    print2dVector(insert(intervals, newInterval));
    cout << "test case 01, version 2:" << endl;
    print2dVector(insert_v2(intervals, newInterval));
    cout << endl;

    // test case 02
    cout << "test case 02, version 1:" << endl;
    vector<vector<int>> intervals2 {
        {1,2}, {3,5}, {6,7}, {8,10}, {12,16}
    };
    vector<int> newInterval2 {4,8};
    print2dVector(insert(intervals2, newInterval2));
    cout << "test case 02, version 2:" << endl;
    print2dVector(insert_v2(intervals2, newInterval2));

    return 0;
}