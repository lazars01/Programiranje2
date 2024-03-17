#include <stdio.h>
#include <stdlib.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    
    int n;
    scanf("%d", &n);
    
    char ime[21];
    
    for(int i = 1; i <= n; i++) {

        sprintf(ime, "%d.txt", i);

        FILE* izlaz = fopen(ime, "w");
        if(izlaz == NULL)
            greska();
        
        for(int j = 0; j < n; j+=i)
            fprintf(izlaz, "%d ", j);
        
        fclose(izlaz);
        
    }
    
    
    return 0;
}
