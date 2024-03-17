#include <stdio.h>
#include <stdlib.h>

#define MAX 101

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main() {
    
    FILE* ulaz = fopen("knjiga.txt", "r");
    if(ulaz == NULL)
        greska();
    
    int br = 0;
    char linija[MAX];
    while(fgets(linija, MAX, ulaz) != NULL) {
        br++;
    }
    
    fprintf(stdout, "%d\n", br);
    
    fclose(ulaz);
    
    return 0;
}
