#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int* alociraj(int n) {
    return malloc(n * sizeof(int));
}

void alociraj2(int** niz, int n) {
    *niz = malloc(n * sizeof(int));
}

int main(int argc, char* argv[]) {
    
    int n;
    scanf("%d", &n);
    
    if(n <= 0)
        greska();
    
    //int* niz = malloc(n * sizeof(int));
    //int* niz  = alociraj(n);
    int* niz;
    alociraj2(&niz , n);
    
    if(niz == NULL)
        greska();
    
    for(int i = 0; i < n; i++)
        scanf("%d", &niz[i]);
    
    for(int i = n - 1; i >= 0; i--)
        printf("%d ", niz[i]);
    printf("\n");
    
    
    free(niz);
    
    return 0;
}
