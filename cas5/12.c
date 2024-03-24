#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

void trougao(int n, int trenutna_linija) {
    if(trenutna_linija > n)
        return;
    
    for(int i = 0; i < n - trenutna_linija; i++)
        printf(" ");
    for(int i = 0; i < trenutna_linija; i++)
        printf("+");
    printf("\n");
    
    trougao(n, trenutna_linija + 1);
}

int main(int argc, char* argv[]) {
    
    trougao(5, 1);
    
    return 0;
}
