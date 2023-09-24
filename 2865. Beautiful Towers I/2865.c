#include <stdio.h>
#include <stdlib.h>

/*
gcc 2865.c -o 2865c && ./2865c
*/

long long maximumSumOfHeights(int* maxHeights, int maxHeightsSize){
    long long ans = 0;

    for (int i = 0; i < maxHeightsSize; ++i) {
        long long *tmp = (long long*)calloc(maxHeightsSize, sizeof(long long));
        *(tmp + i) = *(maxHeights + i);
        long long sum = *(maxHeights + i);

        for (int j = i - 1; j >= 0; --j) {
            *(tmp + j) = (*(tmp + j + 1) < *(maxHeights + j)) ? *(tmp + j + 1) : *(maxHeights + j);
            sum += *(tmp + j);
        }

        for (int k = i + 1; k < maxHeightsSize; ++k) {
            *(tmp + k) = (*(tmp + k - 1) < *(maxHeights + k)) ? *(tmp + k - 1) : *(maxHeights + k);
            sum += *(tmp + k);
        }

        free(tmp);

        ans = (ans > sum) ? ans : sum;
    }

    return ans;
}

int main(int argc, char *argv[]) {

    int maxHeights [] = {5,3,4,1,1};
    // Output: 13
    printf("%lli\n", maximumSumOfHeights(maxHeights, sizeof(maxHeights)/sizeof(int)));

    int maxHeights2 [] = {6,5,3,9,2,7};
    // Output: 22
    printf("%lli\n", maximumSumOfHeights(maxHeights2, sizeof(maxHeights2)/sizeof(int)));

    int maxHeights3 [] = {3,2,5,5,2,3};
    // Output: 18
    printf("%lli\n", maximumSumOfHeights(maxHeights3, sizeof(maxHeights3)/sizeof(int)));

    return 0;
}