#include <string.h>
#include <stdio.h>

#ifdef getline
#undef getline
#endif

int get_line(char s[], int lim) {
    int c, i;

    for(i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if(c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
//    fprintf(stderr, "size: %d", i);
    return i;
}
