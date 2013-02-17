#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char *, int);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while(--argc > 0 && (*++argv)[0] == '-') {
        while ( c= *++argv[0]) {
            switch(c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
        }
    }

    if(argc != 1) {
        printf("Usage: %s -x -n pattern\n", argv[0]);
    } else {
        while (get_line(line, MAXLINE) > 0) {
            lineno++;
            if((strstr(line, *argv) != NULL) != except) {
                if(number) {
                    printf("line: %ld\t", lineno);
                }
                printf("matched pattern: %s", line);
                found++;
            }
            printf("\n");
        }
    }
    printf("\n");
    return found;
}
