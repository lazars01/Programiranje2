#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

void napravi_niz(int* kraj_niza, int broj) {
    if(broj == 0)
        return;
    
    //kraj_niza[0] = broj % 10;
    napravi_niz(kraj_niza - 1, broj / 10);
    kraj_niza[0] = broj % 10;
}

void ispisi_niz(int* niz, int n) {
    if(n == 0)
        return;
    
    printf("%d ", niz[0]);
    ispisi_niz(niz + 1, n - 1);
}

int main(int argc, char* argv[]) {
    
    int niz[100];
    int broj;
    
    scanf("%d", &broj);
    
    napravi_niz(niz + (int)log10(broj), broj);
    ispisi_niz(niz, log10(broj) + 1);
    
    return 0;
}
