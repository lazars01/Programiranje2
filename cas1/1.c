#include <stdio.h>
#include <stdlib.h>

void greska() {
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main() {
    
    FILE* ulaz = fopen("ulaz.txt", "r");
    if(ulaz == NULL) 
        greska();
    
    FILE* izlaz = fopen("izlaz.txt", "w");
    if(izlaz == NULL)
        greska();
    
    // getchar - fgetc
    // scanf("%c", &c) - fscanf
    
    // putchar - fputc
    // printf - fprintf
    
    char c;
//     while( (c = fgetc(ulaz)) != EOF ) {
//         fputc(c, izlaz);
//     }
    
    while(fscanf(ulaz, "%c", &c) == 1){
            fprintf(izlaz, "%c", c);
    }
    
    fclose(ulaz);
    fclose(izlaz);
    
    return 0;
}
