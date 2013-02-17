#include <string.h>
#include <stdio.h>

void reverse(char s[]) {
    int c, i, j;

    for(i = 0, j = strlen(s)-1; i < j; i++, j--){
        c= s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main(){
    char s[10] = {'a', 'c', 'j', 'b', 'z', 's', 'h', 'i', 'p', 'r'};

    reverse(s);
    return 0;
}

