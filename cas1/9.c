#include <stdio.h>

int main(int argc, char* argv[]) {
    
    if(argc == 1) {
        printf("-1\n");
        return 1;
    }
    
    for(int i = 1; i < argc; i++) {
        if(argv[i][0] != '-') 
            continue;
        
        for(int j = 1; argv[i][j] != '\0'; j++)
            printf("%c ", argv[i][j]);
        
    }
    
    printf("\n");
    
    return 0;
}
