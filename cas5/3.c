#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int najveca_cifra(int x) {
    if(x == 0)
        return 0;
    
    int prethodna_najveca = najveca_cifra(x / 10);
    if(prethodna_najveca > x % 10) {
        return prethodna_najveca;
    }
    else
        return x % 10;
}

int main(int argc, char* argv[]) {
    
    int x;
    scanf("%d", &x);
    
    printf("%d\n", najveca_cifra(x));
    
    return 0;
}
