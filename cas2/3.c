#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    
    if(argc != 2) {
        greska();
    }
    
    int k = atoi(argv[1]);
    if(k == 0)
        greska();
    
    int* niz = malloc(k * sizeof(int));
    if(niz == NULL)
        greska();
    
    FILE* ulaz = fopen("brojevi.txt", "r");
    if(ulaz == NULL)
        greska();
    
    int i = 0, broj, dim = k;
    
    while(1) {
        
        if(i == dim) {
            dim += k;
            niz = realloc(niz, dim * sizeof(int));
            if(niz == NULL)
                greska();
        }
        
        fscanf(ulaz, "%d", &broj);
        if(broj == 0)
            break;
        
        niz[i++] = broj;
        
    }
    
    float sredisnji;
    if(i % 2 == 0) {
        sredisnji = (niz[i/2 - 1]  + niz[i/2]) / 2.0;
    }
    else
        sredisnji = niz[i/2];
    
    for(int j = 0; j < i; j++) {
        if(niz[j] > sredisnji)
            printf("%d\n", niz[j]);
    }
    
    
    fclose(ulaz);
    free(niz);
    
    return 0;
}
