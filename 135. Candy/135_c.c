#include <stdio.h>
#include <stdlib.h>

/*
gcc 135_c.c -Wall -o 135_c && ./135_c
*/

int candy(int* ratings, int ratingsSize){
    int *candies = (int *)calloc(ratingsSize, sizeof(int));
    for (int i = 0; i < ratingsSize; ++i) {
        *(candies + i) = 1;
    }

    for (int i = 1; i < ratingsSize; ++i) {
        if (*(ratings + i) > *(ratings + i - 1)) {
            *(candies + i ) = *(candies + i - 1) + 1;
        }
    }

    for (int i = ratingsSize - 2; i >= 0; --i) {
        if (*(ratings + i) > *(ratings + i + 1)) {
            *(candies + i) = (*(candies + i + 1) + 1 > *(candies + i)) ? *(candies + i + 1) + 1 : *(candies + i);
        }
    }

    int ans = 0;
    for (int i = 0; i < ratingsSize; ++i) {
        ans += *(candies + i);
    }

    free(candies);

    return ans;
}

int main(int argc, char *argv[]) {

    int ratings1 [] = {1,0,2};
    printf("%d\n", candy(ratings1, 3));

    int ratings2 [] = {1,2,2};
    printf("%d\n", candy(ratings2, 3));

    int ratings3 [] = {1,2,87,87,87,2,1};
    printf("%d\n", candy(ratings3, 7));

    return 0;
}