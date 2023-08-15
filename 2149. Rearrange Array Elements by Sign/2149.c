#include <stdio.h>
#include <stdlib.h>

/*
gcc 2149.c -o 2149 && ./2149
*/

int* rearrangeArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *ans = (int *)calloc(numsSize, sizeof(int));
    int pos = 0, neg = 1;

    for (int i = 0; i < numsSize; ++i) {
        if (*(nums + i) >= 0) {
            *(ans + pos) = *(nums + i);
            pos += 2;
        }
        else {
            *(ans + neg) = *(nums + i);
            neg += 2;
        }
    }

    return ans;
}

int main(int argc, char *argv[]) {

    int nums [] = {3,1,-2,-5,2,-4};
    int returnSize = 0;
    // Output: [3,-2,1,-5,2,-4]
    int *ans = rearrangeArray(nums, 6, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", *(ans + i));
    }

    return 0;
}