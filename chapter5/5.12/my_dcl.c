#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

void dcl(void);
void dirdcl(void);
int gettoken(void);

enum { NAME, PARENS, BRACKETS };

int tokentype; /*type of last token  ALSO [4] !!! */
char token[MAXTOKEN]; /*last token string */
char name[MAXTOKEN]; /*identifier name */
char datatype[MAXTOKEN]; /*data type = char, int, etc. */
char out[1000];

/*
char (*(*x())[])()
x:  function returning pointer to array[] of pointer to function returning char

char (*(*x[3])())[5]
x:  array[3] of pointer to function returning pointer to array[5] of char
*/
int
main() /* convert declaration to words */
{
    while (gettoken() != EOF) {    /* 1st token on line */
        strcpy(datatype, token);   /* is the datatype */
        out[0] = '\0';
        dcl();            /* parse rest of line */

        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int gettoken(void) /* return next token */
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;        /* [1] */

    while ((c = getch()) == ' ' || c == '\t') {
        /*fprintf(stderr, "ignore such char: %c\n", c);*/
    }

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");            /* [2][3] */
            return tokentype = PARENS;           /* [4] */
        } else {
            ungetch(c);
            return tokentype = '(';
        }

    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;

    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); ) /* SUPPOSING [5] */
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;

    } else
        return tokentype = c;
}

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;
    for (ns = 0; gettoken() == '*'; ) /* count *'s */
        ns++;

    dirdcl();

    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME) /* variable name */
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");

    while ((type=gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}
