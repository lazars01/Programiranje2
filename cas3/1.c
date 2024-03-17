#include <stdio.h>
#include <stdlib.h>

#define MAX 21

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    
    FILE* ulaz = fopen("imena.txt", "r");
    if(ulaz == NULL)
        greska();
    
    char ime[MAX], prezime[MAX];
    while(fscanf(ulaz, "%*d. %s %s %*f", ime, prezime) == 2) {
        printf("%s %s\n", ime, prezime);
    }
    
    fclose(ulaz);
    
    return 0;
}
