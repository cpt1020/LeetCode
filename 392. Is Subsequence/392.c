#include <stdio.h>
#include <stdbool.h>

/*
gcc 392.c -o 392c && ./392c
*/

bool isSubsequence(char * s, char * t){
    int i = 0, j = 0;
    while (*(s + i) != '\0' && *(t+j) != '\0') {
        if (*(s + i) == *(t + j)) {
            i++;
        }
        j++;
    }

    return (*(s + i) == '\0');
}

int main(int argc, char *argv[]) {

    char s[] = "abc";
    char t[] = "ahbgdc";
    printf("%s\n", isSubsequence(s, t) ? "true" : "false");

    char s2[] = "axc";
    printf("%s\n", isSubsequence(s2, t) ? "true" : "false");

    return 0;
}