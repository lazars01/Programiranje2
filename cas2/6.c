#include <stdio.h>
#include <stdlib.h>

void greska(char* poruka) {
    fprintf(stderr, "%s\n", poruka);
    exit(EXIT_FAILURE);
}

typedef struct {
    
    unsigned int a, b;
    char ime[5];
} Pravougaonik;

int main(int argc, char* argv[]) {
    
    
    // moze i odmah da se obradi, ali da vidimo dinamicku
    int k = 10;
    Pravougaonik* niz = malloc(k * sizeof(Pravougaonik));
    if(niz == NULL)
        greska("Niz malloc");

    if(argc != 2)
        greska("argc");
    
    FILE* ulaz = fopen(argv[1], "r");
    if(ulaz == NULL)
        greska("ulaz");
    
    int i = 0;
    int dim = k;
    while(fscanf(ulaz, "%u %u %s", &niz[i].a, &niz[i].b, niz[i].ime) == 3) {
        
        if(niz[i].a == 0 || niz[i].b == 0)
            greska("0");
        
        i++;
        
        if(i == k) {
            dim += k;
            niz = realloc(niz, dim * sizeof(Pravougaonik));
            if(niz == NULL)
                greska("realloc");
        }
    }
    
    unsigned int max_p = 0;
    int br = -1;
    for(int j = 0; j < i; j++) {
        if(niz[j].a == niz[j].b)
            printf("%s\n", niz[j].ime);
        else {
            if(niz[j].a * niz[j].b > max_p) {
                max_p = niz[j].a * niz[j].b;
                br = j;
            }
        }
    }
    
    if(br != -1)
        printf("%d\n", niz[br].a * niz[br].b);
    
    
    fclose(ulaz);
    free(niz);
    
    return 0;
}
