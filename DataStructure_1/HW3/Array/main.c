/*
32210086 강인창
Assignment 3 Polynomial addition(list)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polyArray.h"

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

    poly* pa1 = makePolyArray(d1, len1);
    poly* pa2 = makePolyArray(d2, len2);

    poly* res = addPolyArray(pa1, pa2);
    poly* res2 = subPolyArray(pa1, pa2);

    printPolyArray(pa1); //add
    printPolyArray(pa2); //sub

    printPolyArray(res);
    printPolyArray(res2);

    return 0;
}