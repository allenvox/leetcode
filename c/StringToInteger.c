#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int myAtoi(char *s){
    long int result = 0;
    int sign = 1, signBefore = 0, numsBefore = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] == '+' || s[i] == '-') && (signBefore == 1 || numsBefore == 1)) {
            return sign * result;
        }
        if (s[i] == '-' && signBefore == 0) {
            sign = -1;
            signBefore = 1;
        } else if (s[i] == '+' && signBefore == 0) {
            signBefore = 1;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            numsBefore = 1;
            result = result * 10 + s[i] - '0';
            if (sign * result > INT_MAX) {
                return INT_MAX;
            } else if (sign * result < INT_MIN) {
                return INT_MIN;
            }
        } else if ((s[i] != ' ' && s[i] != '-' && s[i] != '+') || (s[i] == ' ' && (numsBefore == 1 || signBefore == 1))) {
            return sign * result;
        }
    }
    return (int)sign * result;
}

void printMyAtoi (char *s) {
    printf("myAtoi(\"%s\") = %d\n", s, myAtoi(s));
}

int main () {
    printMyAtoi(" -42");
    printMyAtoi("100");
    printMyAtoi("4193 with words");
    printMyAtoi("-5-");
    printMyAtoi("+ 01");
    return 0;
}