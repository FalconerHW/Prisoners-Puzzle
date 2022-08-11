#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "boxes.h"
#include "helper.h"

// Initialised the values of a new array
void initialiseArray(int *array, int size) {
    for (int i = 1; i < size + 1; i++)
        array[i] = UNALLOCATED;
}

// Prints the prisoners who found there box
// 1 is printed for success, and 0 for failure
void showResults(int *results, int size) {
    printf("PRINTING RESULTS\n");
    for (int i = 0; i < size; i++) {
        if (i % (int)sqrt(size) == 0 && i > 0)
            printf("\n");
        printf("%d", results[i + 1]);
        printf(" ");
    }
    printf("\n\n");
}

// Finds whether all prisoners escaped or not
int success(int *results, int size) {
    for (int i = 1; i < size + 1; i++) {
        if (results[i] == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}

// Takes an array, and returns a random integer out of the yet
// to be used array indeces.
int randint(int *array, int size) {
    int r = rand() % (size - 1) + 1;
    if (array[r] == UNALLOCATED) {
        array[r] = ALLOCATED;
        return r;
    }
    return randint(array, size);
}