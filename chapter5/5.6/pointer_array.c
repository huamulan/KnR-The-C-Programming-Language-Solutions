#include <stdio.h>
#include <string.h>

#define MAXLINES 1000

char *lineptr[MAXLINES];

int get_line(char *, int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int main() {
    char *lineptr[MAXLINES] = {"Hello", "World", "!"};
    writelines(lineptr, 3);
    return 0;
}

int readlines(char *lineptr[], int nlines){
    return 0;
}

void writelines(char *lineptr[], int nlines){
    while(nlines--){
        printf("%s\n", *lineptr++);
    }
}
