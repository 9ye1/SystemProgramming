/*
32210086 강인창
Assignment 3 Polynomial addition(list)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polyList.h"

int input2double(double *d, char* input) {
    char *token;
    int count = 0;
    token = strtok(input, " \n");
    while(token != NULL && count < 32) {
        d[count++] = strtod(token, NULL);
        token = strtok(NULL, " \n");
    }
    return count;
}

int main(void) {
    char input[128];
    double d1[32];
    double d2[32];
    int len1, len2;

    printf("Input 1: ");
    gets(input);
    len1 = input2double(d1, input);
    
    printf("Input 2: ");
    gets(input);
    len2 = input2double(d2, input);

    List l1 = makePolyList(d1, len1);
    List l2 = makePolyList(d2, len2);

    List res = addPolyList(l1, l2);
    List res2 = subPolyList(l1, l2);

    printPolyList(l1);
    printPolyList(l2);
    printPolyList(res);
    printPolyList(res2);

    return 0;
}