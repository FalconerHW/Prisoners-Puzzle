#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "boxes.h"
#include "search.h"
#include "helper.h"

#define INVALID 0
#define VALID 1

// Validates the inputs
int validInputs(char *argv[]);

// checks a value is a perfect sqaure
int isPerfectSquare(int value);


// This program takes in 3 parametres:
//  - Method (Loop or Random selection)
//  - Number of prisoners (Must be a perfect square)
//  - Number of trials
// It will then print the rate of success and the number of successful
// escapes.

// In this puzzle there are 100 prisoners, each given a distinct number 1-100. 
// The jailer has decided to give all the prisoners a chance to escape. 
// He prepares a challenge, and if every single one of the prisoners passes, they 
// are all free to go. If even one of them fails, they all die.

int main(int argc, char *argv[]) {
    int numPrisoners = atoi(argv[2]);
    int *(*fn)(int*, int) = NULL;

    if (!validInputs(argv))
        return INVALID;

    if (!strcmp(argv[1], "loop")) {
        fn = loopSearch;
    }
    if (!strcmp(argv[1], "rand")) {
        fn = randSearch;
    }

    double ratio = 0.0;
    int count = 0;
    int trials = atoi(argv[3]);
    if (fn) {
        for (int i = 0; i < trials; i++) {

            // Creates the boxes in a random arrangement
            int *boxes = createBoxes((i + 1) * time(0), numPrisoners);

            // Run the given method and count the success of required
            int *results = fn(boxes, numPrisoners);
            showResults(results, numPrisoners);
            int succ = success(results, numPrisoners);
            count += succ;

            // Updates the rate of success
            ratio = ratio + (double)succ / trials;


            free(results);
            free(boxes);
        }
    }
    printf("Rate of success is: %0.4lf%%\n", 100 * ratio);
    printf("Number of successes was %d/%d\n", count, trials);
    return 0;
}

int validInputs(char *argv[]) {
    if (strcmp(argv[1], "rand") && strcmp(argv[1], "loop")) {
        printf("You didn't enter a valid method\n");
        return INVALID;
    }

    if (!isdigit(*argv[2])) {
        printf("You must enter a valid number of prisoners\n");
        return INVALID;
    }
    if (!isPerfectSquare(atoi(argv[2]))) {
        printf("Number of prisoners must be a perfect square\n");
        return INVALID;
    }

    if (!isdigit(*argv[3])) {
        printf("You must enter a valid number of trials\n");
        return INVALID;
    }

    return VALID;
}

int isPerfectSquare(int value) {
    int intVal = sqrt(value);
    double dblVal = (double)sqrt(value);
    return intVal == dblVal;
}