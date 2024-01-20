#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int variable1 = 0;

int main(int argc, char *argv[]){

    /*
    Studentenfrage
    Speicherorte von globalen vs. stack vs. heap Variablen

    Variable1 - global - 0x100407000
    Variable2 - stack - 0x7ffffcbf4
    Variable3 - heap - 0xa00001ad0  
    
    */

    int variable2 = 0;
    int *variable3 = malloc(sizeof(int));

    printf("Variable1 - global - \t%p\n",&variable1);
    printf("Variable2 - stack - \t%p\n",&variable2);
    printf("Variable3 - heap - \t%p\n",variable3);

    free(variable3);
    return 0;
}
