#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}


int sum_max(int** A, int n, int m) {
    int suma = 0;
    for(int i = 0; i < n; i++) {
        int max = A[i][0];
        for(int j = 1; j < m; j++)
            if(max < A[i][j])
                max = A[i][j];
        
        suma += max;
    }
    
    return suma;
}

void alociraj(int*** A, int n, int m) {
    
    *A = malloc(n * sizeof(int*));
    if(*A == NULL)
        greska();
    for(int i = 0; i < n; i++) {
        (*A)[i] = malloc(m * sizeof(int));
        if((*A)[i] == NULL)
            greska();
    }
    
}

int main(int argc, char* argv[]) {
    
    int n, m;
    scanf("%d%d", &n, &m);
    
    if(n <= 0 || m <= 0)
        greska();
    
    int** mat = malloc(n * sizeof(int*));
    if(mat == NULL)
        greska();
    
    for(int i = 0; i < n; i++) {
        mat[i] = malloc(m * sizeof(int));
        if(mat[i] == NULL)
            greska();
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
    
    
    printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
    
    int max = sum_max(mat, n, m);
    printf("%d\n", max);

        
    
    for(int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
    
    return 0;
}
