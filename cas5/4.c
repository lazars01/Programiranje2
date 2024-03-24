#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

// 98794 9
// 874

int ukloni(int x, int c) {
    if(x == 0)
        return 0;
    
    int prethodni = ukloni(x / 10, c);
    if(x % 10 == c)
        return prethodni;
    else
        return prethodni * 10 + x % 10;
    
}

int main(int argc, char* argv[]) {
    
    int x, c;
    scanf("%d%d", &x, &c);
    
    printf("%d\n", ukloni(x, c));
    
    return 0;
}
