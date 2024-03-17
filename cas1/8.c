#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
    if(argc != 3) {
        printf("-1\n");
        return 1;
    }
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    
    for(int i = a; i <= b; i++)
        printf("%d ", i);
    
    return 0;
}
