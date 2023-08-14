#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n);

int main(int argc, char *argv[]) {
    
    printf("%s\n", isPowerOfTwo(5) ? "true" : "false");
    printf("%s\n", isPowerOfTwo(0) ? "true" : "false");
    printf("%s\n", isPowerOfTwo(1024) ? "true" : "false");

    return 0;
}

bool isPowerOfTwo(int n){
    int ones = 0;
    while (n != 0) {
        if (n & 1 == 1 && ones == 0) {
            ones += 1;
        }
        else if (n & 1 == 1 && ones == 1) {
            return false;
        }

        n >>= 1;
    }

    return ones;
}