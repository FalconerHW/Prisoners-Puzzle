#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "search.h"
#include "helper.h"

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

int *randSearch(int *boxes, int size) {
    int *results = malloc(size * sizeof(int));
    initialiseArray(results, size);

    for (int i = 0; i < size; i++) {
        results[i] = doRandSearch(boxes, i, size);
        // printf("Result %d is %d\n", i, results[i]);
    }
    // showResults(results);
    return results;
}

int doRandSearch(int *boxes, int search, int size) {
    int numSearches = size / 2;
    int *visited = malloc(size * sizeof(int));
    initialiseArray(visited, size);

    for (int i = 0; i < numSearches; i++) {
        int r = randint(visited, size);
        // printf("rand int is %d\n", r);
        if (boxes[r] == search) {
            free(visited);
            return SUCCESS;
        }
    }
    free(visited);
    return FAILURE;
}