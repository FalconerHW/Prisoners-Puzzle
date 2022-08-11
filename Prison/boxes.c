#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "boxes.h"
#include "helper.h"

int *createBoxes(int seed, int size) {
    srand(seed);

    int *prisoners = malloc((size + 2) * sizeof (int));
    int *boxes = malloc((size + 2) * sizeof (int));

    initialiseArray(prisoners, (size + 1));

    for (int i = 1; i < size + 1; i++)
        boxes[i] = randint(prisoners, size + 1); 
    free(prisoners);
    return boxes;
}


void printBoxes(int *boxes, int size) {
    for (int i = 1; i < size + 1; i++) {
        if ((i - 1) % (int)sqrt(size) == 0 && i > 1)
            printf("\n");
        
        printf("%d", boxes[i]);
        
        if (boxes[i] < 10)
            printf("  ");
        else
            printf(" ");
    }
    printf("\n");
}
