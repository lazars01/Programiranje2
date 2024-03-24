#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}


int dodaj_0(int x) {
    if(x == 0)
        return 0;
    
    int broj = dodaj_0(x / 10);
    if(x % 2 == 1)
        return broj * 100 + x % 10 * 10;
    else
        return broj*10 + x % 10;
}

int main(int argc, char* argv[]) {
    
    int x;
    scanf("%d", &x);
    printf("%d\n", dodaj_0(x));
    
    return 0;
}
