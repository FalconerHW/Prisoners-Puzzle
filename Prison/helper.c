#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "boxes.h"
#include "helper.h"

void initialiseArray(int *array, int size) {
    for (int i = 1; i < size + 1; i++)
        array[i] = UNALLOCATED;
}

void showResults(int *results, int size) {
    for (int i = 0; i < size; i++) {
        if (i % (int)sqrt((double)size) == 0 && i > 0)
            printf("\n");
        printf("%d", results[i + 1]);
        printf(" ");
    }
    printf("\n");
}

int success(int *results, int size) {
    for (int i = 1; i < size + 1; i++) {
        if (results[i] == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

int randint(int *array, int size) {
    int r = rand() % (size - 1) + 1;
    if (array[r] == UNALLOCATED) {
        array[r] = ALLOCATED;
        return r;
    }
    return randint(array, size);
}