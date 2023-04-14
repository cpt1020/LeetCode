#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans {0};
        
        while (n > 0) {
            ans += (n & 1);
            n >>= 1;
        }
        return ans;
    }
};

int main() {

    Solution sol;

    cout << sol.hammingWeight(00000000000000000000000000001011) << endl;
    cout << sol.hammingWeight(00000000000000000000000010000000) << endl;

    return 0;
}