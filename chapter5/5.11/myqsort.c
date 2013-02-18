#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmstringp(const void *p1, const void *p2);
static void myqsort(void *v[], int left, int right, int (*comp)(void *, void *));

static int
cmpstringp(const void *p1, const void *p2)
{
    /* The actual arguments to this function are "pointers to
       pointers to char", but strcmp(3) arguments are "pointers
       to char", hence the following cast plus dereference */
    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

static void 
myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if(left >= right) {
        return;
    }
    swap(v, left, (left + right)/2);
    last = left;

    for(i = left + 1; i <= right; i++) {
        if((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);

    myqsort(v, left, last - 1, comp);
    myqsort(v, last + 1, right, comp);
}

void
swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int
main(int argc, char *argv[])
{
    int j;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "argc: %d, sizeof(argv[1]): %ld\n", argc, sizeof(argv[1]));

    //Pay attention, the last index should be argc - 2. Please take care.
    myqsort((void **)&argv[1], 0, argc - 2, (int (*)(void *, void *))strcmp);

    // We call the standard qsort function here,
    // pay attention the 2nd and 3rd parameters is not the same as ours.
    //qsort((void **)&argv[1], argc - 1, sizeof(argv[1]), cmpstringp);

    for (j = 1; j < argc; j++)
        puts(argv[j]);

    exit(EXIT_SUCCESS);
}
