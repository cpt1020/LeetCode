#include <stdio.h>
#include <stdlib.h>

/*
gcc 799.c -o 799c && ./799c
*/

double champagneTower(int poured, int query_row, int query_glass){
    double *cur_row = (double*)calloc(1, sizeof(double));
    *(cur_row) = poured;

    for (int i = 0; i <= query_row; ++i) {
        double *next_row = (double*)calloc(i + 2, sizeof(double));
        for (int j = 0; j <= i; ++j) {
            if (*(cur_row + j) > 1) {
                *(cur_row + j) -= 1;
                *(next_row + j) += *(cur_row + j)/2;
                *(next_row + j + 1) += *(cur_row + j)/2;
                *(cur_row + j) = 1;
            }
        }

        if (i != query_row) {
            free(cur_row);
            cur_row = next_row;
        }
    }

    return *(cur_row + query_glass);
}

int main(int argc, char *argv[]) {

    int poured = 1, query_row = 1, query_glass = 1;
    // Output: 0.00000
    printf("%f\n", champagneTower(poured, query_row, query_glass));

    poured = 2, query_row = 1, query_glass = 1;
    // Output: 0.50000
    printf("%f\n", champagneTower(poured, query_row, query_glass));

    poured = 100000009, query_row = 33, query_glass = 17;
    // Output: 1.00000
    printf("%f\n", champagneTower(poured, query_row, query_glass));

    return 0;
}