#include <stdio.h>
#include <stdlib.h>

#include "polinomi.h"

int main(int argc, char* argv[]) {
    
    int n;
    int* polinom = unos(&n);
    
    ispis_polinoma(polinom, n);
    
    int m;
    int* polinom2 = unos(&m);
    
    ispis_polinoma(polinom2, m);
    
    int* c;
    int dim = suma_polinoma(polinom, n, polinom2, m, &c);
    
    //ispis_polinoma(c, dim);
    
    mnozenje_skalarom(c, dim, 5);
    //ispis_polinoma(c, dim);
    
    //printf("%d\n", vr_poly(c, dim, 2));
    
    int* mnozenje;
    int dim_mn = mnozenje_polinoma(polinom, n, polinom2, m, &mnozenje);
    
    ispis_polinoma(mnozenje, dim_mn);
    
    free(polinom);
    free(polinom2);
    free(c);
    free(mnozenje);
    
    return 0;
}
