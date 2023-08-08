#include <stdio.h>

int minBitFlips(int start, int goal){
    int xor = start ^ goal;
    int ans = 0;
    while (xor != 0) {
        ans += (xor & 1);
        xor >>= 1;
    }
    return ans;
}

int main(int argc, char **argv) {

    int (*fun_ptr) (int, int);
    fun_ptr = minBitFlips;

    printf("%d\n", fun_ptr(10, 7));
    printf("%d\n", fun_ptr(3, 4));

    return 0;
}