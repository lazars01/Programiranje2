#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

void okreni_niz(int* niz, int n) {
    
    if(n <= 1)
        return;
    
    int tmp = niz[0];
    niz[0] = niz[n - 1];
    niz[n - 1] = tmp;
        
    okreni_niz(niz + 1, n - 2);
    
}

void ispisi_niz(int* niz, int n) {
    if(n == 0)
        return;
    
    printf("%d ", niz[0]);
    ispisi_niz(niz + 1, n - 1);
}

int main(int argc, char* argv[]) {

    
    int n;
    scanf("%d", &n);
    int* niz = malloc(n * sizeof(int));
    if(niz == NULL)
        greska();

    for(int i = 0; i < n; i++)
        scanf("%d", &niz[i]);
    
    okreni_niz(niz, n);
    ispisi_niz(niz, n);
    
    free(niz);
    
    return 0;
}
