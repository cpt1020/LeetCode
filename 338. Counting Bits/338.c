#include <stdio.h>
#include <stdlib.h>

/*
gcc 338.c -o 338 && ./338
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize = n + 1;
    int *ans = (int *)malloc(*(returnSize) * sizeof(int));

    for (int i = 0; i <= n; ++i) {
        int num = i;
        int ones = 0;
        while (num != 0) {
            ones += (num & 1 == 1) ? 1 : 0;

            num >>= 1;
        }
        *(ans + i) = ones;
    }

    return ans;
}

int main(int argc, char *argv[]) {
    int n = 5;
    int returnSize = 0;
    int *res = countBits(n, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", *(res + i));
    }
    printf("\n");
}