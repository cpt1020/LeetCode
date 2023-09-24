#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans {0}, cur {0};
        int size = maxHeights.size();
        vector<long long> left (size);
        vector<int> st {-1};

        for (int i {0}; i < size; ++i) {
            while (st.size() > 1 && maxHeights.at(st.back()) > maxHeights.at(i)) {
                int idx {st.back()};
                st.pop_back();
                cur -= 1ll * (idx - st.back()) * maxHeights.at(idx);
            }

            cur += 1ll * (i - st.back()) * maxHeights.at(i);
            st.push_back(i);
            left.at(i) = cur;
        }

        st = {size};
        cur = 0;
        vector<long long> right (size);
        for (int i {size - 1}; i >= 0; --i) {
            while (st.size() > 1 && maxHeights.at(st.back()) > maxHeights.at(i)) {
                int idx {st.back()};
                st.pop_back();
                cur -= 1ll * (st.back() - idx) * maxHeights.at(idx);
            }

            cur += 1ll * (st.back() - i) * maxHeights.at(i);
            st.push_back(i);
            right.at(i) = cur;
        }

        for (int i {0}; i < size; ++i) {
            long long height {left.at(i) + right.at(i) - maxHeights.at(i)};
            ans = max(ans, height);
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