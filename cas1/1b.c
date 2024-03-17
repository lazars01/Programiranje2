#include <stdio.h>
#include <stdlib.h>

#define MAX 81

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main() {
    
    FILE* ulaz = fopen("ulaz.txt", "r");
    if(ulaz == NULL) 
        greska();
    
    FILE* izlaz = fopen("izlaz.txt", "w");
    if(izlaz == NULL)
        greska();
    
    
    char linija[MAX];
    
    while(fgets(linija, MAX, ulaz) != NULL) {
        fputs(linija, izlaz);
    }
    
    fclose(ulaz);
    fclose(izlaz);
    
    return 0;
}
