#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void greska(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main() {
    
    FILE* matrica = fopen("matrica.txt", "r");
    if(matrica == NULL)
        greska();
    
    int n, m, mat[MAX][MAX];
    fscanf(matrica, "%d%d", &n, &m);
    
    if(n <= 0 || n > 50)
        greska();
    if(m <= 0 || m > 50)
        greska();
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            fscanf(matrica, "%d", &mat[i][j]);
        
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int suma = 0;
            
            for(int k = -1; k <= 1; k++)
                for(int l = -1; l <= 1; l++) {
                    if(k == 0 && l == 0)
                        continue;
                    
                    if(i+k < 0 || i + k >= n)
                        continue;
                    if(j + l < 0 || j + l >= m)
                        continue;
                    
                    suma += mat[i+k][j+l];
                }
            
            if(mat[i][j] == suma)
                printf("(%d, %d, %d)\n", i, j, mat[i][j]);
            
        }
    
    fclose(matrica);
    return 0;
    
}
