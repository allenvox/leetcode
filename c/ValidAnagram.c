#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char *s, char *t) {
    if(strlen(s) != strlen(t)) return false;
    int count1[26] = {0}, count2[26] = {0};
    for(int i = 0; i < (int)strlen(s); i++) {
        count1[s[i] - 'a']++;
        count2[t[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(count1[i] != count2[i]) return false;
    }
    return true;
}

void output(char *s, char *t) {
    printf("Word \"%s\" is ", t);
    if(!isAnagram(s, t)) printf("not ");
    printf("an anagram to word \"%s\"\n", s);
}

int main() {
    output("anagram", "nagaram");
    output("rat", "car");
    return 0;
}