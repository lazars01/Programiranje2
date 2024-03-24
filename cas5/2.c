#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int broj_parnih(int x) {
    
    if(x == 0)
        return 0;
    
    int br = broj_parnih(x / 10);
    if(x % 2 == 0)
        return 1 + br;
    else
        return br;
    
}

int main(int argc, char* argv[]) {
    
    int x;
    scanf("%d", &x);
    
    printf("%d\n", broj_parnih(x));
    
    return 0;
}
