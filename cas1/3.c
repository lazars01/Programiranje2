#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 21

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main() {
    
    char ulaz[MAX], izlaz[MAX], c;
    scanf("%s%s %c", ulaz, izlaz, &c);
    
    if(c != 'u' && c != 'l')
        greska();
    
    FILE* input = fopen(ulaz, "r");
    if(input == NULL)
        greska();
    
    FILE* output = fopen(izlaz, "w");
    if(output == NULL)
        greska();
    
    char karakter;
    while( (karakter = fgetc(input)) != EOF) {
        if(c == 'u')
            fputc(toupper(karakter), output);
        else
            fputc(tolower(karakter), output);
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}
