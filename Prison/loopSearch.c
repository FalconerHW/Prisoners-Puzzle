#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "search.h"
#include "helper.h"

int *loopSearch(int *boxes) {
    int *results = malloc(NUM_PRISONERS * sizeof(int));
    initialiseArray(results, NUM_PRISONERS);

    for (int i = 0; i < NUM_PRISONERS; i++)
        results[i] = doLoopSearch(boxes, i);
    return results;
}

int doLoopSearch(int *boxes, int search) {
    int searchBox = search;
    for (int i = 0; i < NUM_PRISONERS / 2; i++) {
        if (boxes[searchBox] == search)
            return SUCCESS;
        else
            searchBox = boxes[searchBox];
    }
    return FAILURE;
}