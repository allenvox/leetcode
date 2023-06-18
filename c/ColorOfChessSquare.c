#include <stdio.h>
#include <stdbool.h>

bool squareIsWhite(char *coordinates) {
    int letter = coordinates[0] % 2; // a, c, e, g - odd, other - even
    int num = coordinates[1] % 2; // 1, 3, 5, 7 - odd, other - even
    if(letter == num) return false; // if both odd or even - square is black
    return true; // else - square is white
}

void output(char *coordinates) {
    printf("Chess square with coordinates \"%s\" is ", coordinates);
    if(squareIsWhite(coordinates)) {
        printf("white");
    } else {
        printf("black");
    }
    printf("\n");
}

int main() {
    output("a1");
    output("h3");
    output("c7");
    return 0;
}