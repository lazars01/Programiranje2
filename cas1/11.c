#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL));
    
    printf("%.2f\n", (float)rand() / RAND_MAX);
    
    return 0;
}
