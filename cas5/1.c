#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

void ispis1(int x) {
    if(x < 10) {
        printf("%d", x);
        return;
    }
    
    printf("%d", x % 10);
    ispis1(x / 10);        
}

void ispis2(int x) {
    if(x == 0)
        return;
    
    ispis2(x / 10);
    printf("%d", x % 10);
}

int main(int argc, char* argv[]) {
    
    int x;
    scanf("%d", &x);
    
    ispis1(x);
    printf("\n");
    ispis2(x);

    
    return 0;
}
