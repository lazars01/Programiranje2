#include "polinomi.h"

#include <stdlib.h>
#include <stdio.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int* unos(int* n) {
    scanf("%d", n);
    
    int* koeficijenti = malloc((*n + 1) * sizeof(int));
    if(koeficijenti == NULL)
        greska();
    
    for(int i = 0; i < *n + 1; i++)
        scanf("%d", &koeficijenti[i]);
        
    return koeficijenti;
}

void ispis_polinoma(int* a, int n) {
    for(int i = 0; i < n + 1; i++) {
        if(i == 0)
            printf("%d", a[0]);
        else {
            if(a[i] > 0)
                printf(" + %d*x^%d", a[i], i);
            else if(a[i] < 0)
                printf(" - %d*x^%d", -1*a[i], i);
        }
    }
    printf("\n");
}

int suma_polinoma(int* a, int m, int *b, int n, int** c){
    
    int max = m > n ? m : n ; 
    int min = m < n ? m : n ;
    int id = 0;
    if (n == min)
        id = 1;
    
    *c = malloc(max * sizeof (int));
    if(*c == NULL)
    greska();
    
    int i;
    for(i = 0 ; i < min + 1 ; i++){
        
        (*c)[i] = a[i] + b[i];
        
    }
    for(; i < max + 1 ; i++){
        
        if(id)
            (*c)[i] = a[i];
        else 
            (*c)[i] = b[i];
        
    }
    i--;
    for(; (*c)[i] == 0 ; i--){
    }
    
    return i;
    
}

void mnozenje_skalarom(int* a, int n, int c) {
    for(int i = 0; i < n + 1; i++)
        a[i] *= c;
}

int vr_poly(int* a, int n, int x) {
  
    int vrednost = 0;
    for(int i = n; i >= 0; i--) {
        vrednost *= x;
        vrednost += a[i];
    }
    return vrednost;
}

int mnozenje_polinoma(int* a, int m, int* b, int n, int** c) {
    
    *c = calloc( (m + n + 1),  sizeof(int));
    if(*c == NULL)
        greska();
    
    for(int i = 0; i < m + 1; i++) {
        for(int j = 0; j < n + 1; j++) {
            (*c)[i + j] += a[i] * b[j];
        }
    }
    
    return m + n;
}
