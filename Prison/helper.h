#define UNALLOCATED 0
#define ALLOCATED 1
#define FAILURE 0
#define SUCCESS 1

void initialiseArray(int *array, int size);
void showResults(int *results, int size);
int success(int *results, int size);
int randint(int *array, int size);