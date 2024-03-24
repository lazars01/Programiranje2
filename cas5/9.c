#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int palindrom(int* niz, int n) {
    if(n <= 1)
        return 1;
    
    if(niz[0] != niz[n-1])
        return 0;
    
    return palindrom(niz + 1, n - 2);
}

int main(int argc, char* argv[]) {
    
    int n;
    scanf("%d", &n);
    int* niz = malloc(n * sizeof(int));
    if(niz == NULL)
        greska();

    for(int i = 0; i < n; i++)
        scanf("%d", &niz[i]);
    
    printf("%d\n", palindrom(niz, n));

    free(niz);
    
    return 0;
}
