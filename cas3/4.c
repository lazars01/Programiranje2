#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    
    if(argc != 2)
        greska();
    
    FILE* ulaz = fopen(argv[1], "r");
    if(ulaz == NULL)
        greska();
    
    int n;
    char rec[MAX];
    
    scanf("%d %s", &n, rec);
    
    char* lineptr = NULL;
    size_t size = 0;
    
    int procitano, k, br_reci;
    char tmp[MAX];
    
    while(getline(&lineptr, &size, ulaz) != EOF) {
        
        procitano = 0;
        br_reci = 0;
        
        while(sscanf(lineptr + procitano, "%s%n", tmp, &k) == 1) {
            procitano += k;
            
            if(strcmp(rec, tmp) == 0)
                br_reci++;
        }
        
        if(br_reci == n)
            printf("%s", lineptr);
    }
  
    free(lineptr);
    fclose(ulaz);
    
    return 0;
}
