/*
 * Filename:    shellsort.c
 * Author:      Bonder Wu <bonderwu@gmail.com>
 * Date:        15-JAN-2012
 *
 * The C Programming Language, second edition,
 * by Brian Kernighan and Dennis Ritchie
 *
 */
#include <stdio.h>

void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for(gap = n/2; gap > 0; gap /= 2){
        for(i = gap; i < n; i++) {
            for(j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

int main() {
    int v[10] = {4, 1, 2, 7, 9, 6, 3, 8, 5, 0};
    int i = 0;

    shellsort(v, sizeof(v) / sizeof(int));

    for(i = 0; i < sizeof(v)/ sizeof(int); i++) {
        printf("%d\t", v[i]);
    }
    printf("\n");
    return 0;
}
