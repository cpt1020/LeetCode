#include <stdio.h>
#include <stdlib.h>

int countGoodSubstrings(char * s){

    if (s[1] == '\0' || s[2] == '\0') {
        return 0;
    }

    int *alpha = (int *) calloc(26, sizeof(int));
    alpha[*(s+0) - 'a'] += 1;
    alpha[*(s+1) - 'a'] += 1;

    int ans = 0;

    for (char *ptr = (s + 2); *ptr != '\0'; ++ptr) {
        if (ptr - 3 >= s) {
            alpha[*(ptr - 3) - 'a'] -= 1;
        }

        alpha[*(ptr) - 'a'] += 1;
        if (alpha[*(ptr) - 'a'] == 1 && alpha[*(ptr - 1) - 'a'] == 1 && alpha[*(ptr - 2) - 'a'] == 1) {
            ans += 1;
        }
    }

    return ans;
}

int main(int argc, char *argv[]) {

    char s[] = "xyzzaz";
    // Output: 1
    printf("%d\n", countGoodSubstrings(s));


    char s1[] = "aababcabc";
    // Output: 4
    printf("%d\n", countGoodSubstrings(s1));

    return 0;
}