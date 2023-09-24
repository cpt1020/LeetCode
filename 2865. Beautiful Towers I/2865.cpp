#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans {0};
        for (int i {0}; i < maxHeights.size(); ++i) {
            vector<long long> tmp (maxHeights.size());
            tmp.at(i) = maxHeights.at(i);
            long long sum {tmp.at(i)};
            
            for (int j {i - 1}; j >= 0; --j) {
                tmp.at(j) = (tmp.at(j+1) < maxHeights.at(j)) ? tmp.at(j+1) : maxHeights.at(j);
                sum += tmp.at(j);
            }
            
            for (int k {i + 1}; k < maxHeights.size(); ++k) {
                tmp.at(k) = (tmp.at(k-1) < maxHeights.at(k)) ? tmp.at(k-1) : maxHeights.at(k);
                sum += tmp.at(k);
            }
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> maxHeights {5,3,4,1,1};
    // Output: 13
    cout << sol.maximumSumOfHeights(maxHeights) << endl;

    maxHeights = {6,5,3,9,2,7};
    // Output: 22
    cout << sol.maximumSumOfHeights(maxHeights) << endl;

    maxHeights = {3,2,5,5,2,3};
    // Output: 18
    cout << sol.maximumSumOfHeights(maxHeights) << endl;

    return 0;
}