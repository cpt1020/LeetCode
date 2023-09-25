#include <stdio.h>

/*
gcc 389.c -o 389 && ./389
*/

char findTheDifference01(char * s, char * t){
    int alphabet [26] = {0};

    for (int i = 0; s[i] != '\0'; ++i) {
        alphabet[s[i] - 'a'] += 1;
    }

    for (int i = 0; t[i] != '\0'; ++i) {
        if (--alphabet[t[i] - 'a'] == -1) {
            return t[i];
        }
    }

    return '\0';
}

char findTheDifference02(char * s, char * t){
    int sum = 0;
    for (int i = 0; t[i] != '\0'; ++i) {
        sum += t[i];
    }
    for (int i = 0; s[i] != '\0'; ++i) {
        sum -= s[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {

    char s1 [] = "abcd";
    char t1 [] = "abcde";
    printf("%c\n", findTheDifference01(s1, t1));
    printf("%c\n", findTheDifference02(s1, t1));

    char s2 [] = "";
    char t2 [] = "y";
    printf("%c\n", findTheDifference01(s2, t2));
    printf("%c\n", findTheDifference02(s2, t2));

    return 0;
}