#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getSmallestString01(int n, int k) {
        string ans {""};
        for (int i {0}; i < n; ++i) {
            int idx {k - (26 * (n - 1 - i))};
            
            if (idx <= 0) {
                ans += 'a';
                k -= 1;
            }
            else {
                ans += ('a' + idx - 1);
                k -= idx;
            }
        }
        return ans;
    }

    string getSmallestString02(int n, int k) {
        string ans (n, 'a');
        k -= n;
        while (k > 0) {
            ans.at(--n) += min(25, k);
            k -= min(25, k);
        }
        return ans;
    }
};

int main() {

    Solution sol;

    cout << sol.getSmallestString01(3, 27) << endl;
    cout << sol.getSmallestString02(3, 27) << endl;
    cout << sol.getSmallestString01(5, 73) << endl;
    cout << sol.getSmallestString02(5, 73) << endl;

    return 0;
}