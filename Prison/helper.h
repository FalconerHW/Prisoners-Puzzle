#define UNALLOCATED 0
#define ALLOCATED 1
#define FAILURE 0
#define SUCCESS 1

// Initialised the values of a new array
void initialiseArray(int *array, int size);

// Prints the prisoners who found there box
// 1 is printed for success, and 0 for failure
void showResults(int *results, int size);

// Finds whether all prisoners escaped or not
int success(int *results, int size);

// Takes an array, and returns a random integer out of the yet
// to be filled array indeces.
int randint(int *array, int size);