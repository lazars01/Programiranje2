#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    
    //printf("%d\n", rand());
    
    int a, b;
    scanf("%d%d", &a, &b);
    
    
    srand(time(NULL));
    printf("%f\n", ((float)rand()/RAND_MAX) * (b - a) + a);
    
    return 0;
}
