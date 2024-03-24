#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

void hex(int x) {
    if(x == 0)
        return;
    
    hex(x / 16);
    if(x % 16 < 10) {
        printf("%d", x % 16);
        return;
    }

    // x % 16 > = 10 -- ovde
    // ostatak = 10 - A
    // ostatak = 11 - B
    printf("%c", 'A' + x % 16 - 10);

}

int main(int argc, char* argv[]) {
    
    hex(2356);
    printf("\n");
    
    return 0;
}
