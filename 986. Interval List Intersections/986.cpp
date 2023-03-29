#include <iostream>
#include <vector>
#include "../utils.h"
using namespace std;

/*
g++ 986.cpp ../utils.cpp -std=c++17 -o 986 && ./986
*/

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    vector<vector<int>> ans;

    int i {0}, j {0};
    // pointer i and pointer j

    while (i < firstList.size() && j < secondList.size()){
        if (firstList.at(i).at(0) <= secondList.at(j).at(1) && firstList.at(i).at(1) >= secondList.at(j).at(0)){
            // this means both intervals intersect

            int startPoint {max(firstList.at(i).at(0), secondList.at(j).at(0))};
            int endPoint {min(secondList.at(j).at(1), firstList.at(i).at(1))};
            ans.push_back({startPoint, endPoint});
        }

        // decide which pointer to increase according to the endPoint
        // endPoint with larger value means this interval covers broader range
        // therefore, we should increment the pointer which indicates the interval with smaller value of endPoint
        if (firstList.at(i).at(1) <= secondList.at(j).at(1)){
            ++i;
        }
        else {
            ++j;
        }
    }
    
    return ans;
}

int main(){
    
    vector<vector<int>> firstList { {0,2},{5,10},{13,23},{24,25} };
    vector<vector<int>> secondList { {1,5},{8,12},{15,24},{25,26} };

    print2dVector(intervalIntersection(firstList, secondList));

    return 0;
}