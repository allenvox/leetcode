#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int myAtoi (char *s){
    long int result = 0;
    int sign = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (result == 0 && s[i] == '-') {
            sign *= -1;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'z' && result == 0) {
            return result;
        }
    }
    return (int)result * sign;
}

void printMyAtoi (char *s) {
    printf("myAtoi(\"%s\") = %d\n", s, myAtoi(s));
}

int main () {
    printMyAtoi(" -42");
    printMyAtoi("100");
    printMyAtoi("4193 with words");
    return 0;
}