#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 51
#define MAX2 21

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main() {
    
    char dat[MAX2];
    scanf("%s", dat);
    
    FILE* ulaz = fopen(dat, "r");
    if(ulaz == NULL)
            greska();
    
    FILE* izlaz = fopen("rez.txt", "w");
    if(izlaz == NULL)
        greska();
    
    int n;
    fscanf(ulaz, "%d", &n);
    
    char prva[MAX];
    fscanf(ulaz, "%s", prva);
    printf("%s ", prva);
    if(strchr(prva, '_') != NULL)
        fprintf(izlaz, "%s ", prva);
    char rec[MAX];
    for(int i = 1; i < n; i++) {
        fscanf(ulaz, "%s", rec);
        printf("%s ", rec);
        
        if(strstr(rec, prva) != NULL && strchr(rec, '_') != NULL)
            fprintf(izlaz, "%s ", rec);
    }
    printf("\n");
    fprintf(izlaz, "\n");
    
    
    fclose(ulaz);
    
    return 0;
}
