#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "search.h"
#include "helper.h"

// The strategy is amazingly simple. First of all you open up the box corresponding 
// to your own number. If you find your ticket, great!, if not you look up the number 
// on the ticket in your box and that is the box your check next. You carry on this 
// strategy … daisy-chaining your way through the boxes. That's it!
int *loopSearch(int *boxes, int size) {
    int *results = malloc(size * sizeof(int));
    initialiseArray(results, size);

    for (int i = 1; i < size + 1; i++)
        results[i] = doLoopSearch(boxes, i, size);
    return results;
}

int doLoopSearch(int *boxes, int search, int size) {
    int searchBox = search;
    for (int i = 0; i < size / 2; i++) {
        if (boxes[searchBox] == search)
            return SUCCESS;
        else
            searchBox = boxes[searchBox];
    }
    return FAILURE;
}

// This strategy is simple - just pick random boxes until you find your number
// or hit your limit
int *randSearch(int *boxes, int size) {
    int *results = malloc(size * sizeof(int));
    initialiseArray(results, size);

    for (int i = 0; i < size; i++) {
        results[i] = doRandSearch(boxes, i, size);
    }
    return results;
}

int doRandSearch(int *boxes, int search, int size) {
    int numSearches = size / 2;
    int *visited = malloc(size * sizeof(int));
    initialiseArray(visited, size);
    for (int i = 0; i < numSearches; i++) {
        int r = randint(visited, size);
        if (boxes[r] == search) {
            free(visited);
            return SUCCESS;
        }
    }
    free(visited);
    return FAILURE;
}