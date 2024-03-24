#include <stdio.h>
#include <stdlib.h>

#include <math.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

// 1234
// 4*10^3 + 3*10^2 + 2*10^2 + 1*10

int okreni(int broj, int p) {
    if(p == 0)
        return broj;
    
    return broj % 10 * pow(10, p) + okreni(broj / 10, p - 1);
}

int main(int argc, char* argv[]) {
    
    int broj, p;
    scanf("%d", &broj);
    
    p = (int)log10(broj);
    
    //printf("%d\n", p);
    printf("%d\n", okreni(broj, p));
    
    return 0;
}
