#include <stdio.h>
#include <stdlib.h>

/*
gcc 2864c.c -o 2864c && ./2864c
*/

char* maximumOddBinaryNumber(char* s){
    int ones = 0, zeros = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '0') {
            zeros += 1;
        }
        else {
            ones += 1;
        }
    }

    // char ans [ones + zeros + 1];
    char *ans = calloc(ones + zeros + 1, sizeof(char));

    for (int i = 0; i < ones - 1; ++i) {
        // ans[i] = '1';
        *(ans + i) = '1';
    }

    for (int i = 0; i < zeros; ++i) {
        // ans[i + ones - 1] = '0';
        *(ans + i + ones - 1) = '0';
    }

    // ans[ones + zeros - 1] = '1';
    *(ans + ones + zeros - 1) = '1';
    // ans[ones + zeros] = '\0';
    *(ans + ones + zeros) = '\0';

    return ans;
}

int main(int argc, char *argv []) {

    char s [] = "010";
    printf("%s\n", maximumOddBinaryNumber(s));

    char s2 [] = "0101";
    printf("%s\n", maximumOddBinaryNumber(s2));

    return 0;
}