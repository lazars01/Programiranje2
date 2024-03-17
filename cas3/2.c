#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void greska() {
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}

int ispravan_razlomak(char razlomak[]) {
    
    int br_crta = 0;
    for(int i = 0; razlomak[i]; i++) {
        if(!isdigit(razlomak[i]) && razlomak[i] != '/')
            return 0;
        
        if(razlomak[i] == '/')
            br_crta++;
    }
    
    if(br_crta != 1)
        return 0;
    if(razlomak[0] == '/' || razlomak[strlen(razlomak) - 1] == '/')
        return 0;
    
    return 1;
}

int main(int argc, char* argv[]) {
    
    for(int i = 1; i < argc; i++) {
        if(ispravan_razlomak(argv[i]) == 0)
            greska();
        
        int br, im;
        sscanf(argv[i], "%d/%d", &br, &im);
        
        printf("%.2f\n", 1.0 * br / im);
        
    }
    
    return 0;
}
