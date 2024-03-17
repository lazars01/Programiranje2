#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {

    char* rec = malloc(MAX);
    if(rec == NULL)
        greska();
    
    scanf("%s", rec);
    
    int n;
    scanf("%d", &n);
    
    char* uneta = malloc(MAX);
    if(uneta == NULL)
        greska();
    
    int prvi = -1, poslednji = -1;
    
    for(int i = 0; i < n; i++) {
        scanf("%s", uneta);
        
        if(strcmp(uneta, rec) == 0) {
            if(prvi == -1) {
                prvi = i;
                poslednji = i;
            }
            else
                poslednji = i;
        }
        
    }
    
    printf("%d %d\n", prvi, poslednji);
    
    free(uneta);
    free(rec);
    
    return 0;
}
