#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

typedef struct {
    
    int br;
    int im;
} Razlomak;

int main(int argc, char* argv[]) {
    
    int n;
    scanf("%d", &n);
    
    if(n <= 0)
        greska();
    
    Razlomak* niz = malloc(n * sizeof(Razlomak));
    if(niz == NULL)
        greska();
    
    float suma = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &niz[i].br, &niz[i].im);
        suma += (float) niz[i].br / niz[i].im;
    }
    
    float prosek = suma / n;
    
    
    for(int i = 0; i < n; i++) {
        if(prosek < (float) niz[i].br / niz[i].im)
            printf("%d/%d\n", niz[i].br, niz[i].im);
    }
    
    
    free(niz);
    
    return 0;
}
