#include <stdio.h>
#include <stdlib.h>
#include "urandom_parser.h"

int main(int argc, char **argv){
    
    struct arguments arguments;
    arguments.bytes = NULL;
    arguments.base = 0;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    int length = atoi(arguments.bytes);
    int display = arguments.base;

    unsigned char *key = (unsigned char *) malloc(sizeof(unsigned char)*length);
    FILE* random = fopen("/dev/urandom", "r");
    fread(key, sizeof(unsigned char)*length, 1, random);
    fclose(random);
    
    if (display){
        for (int i=0; i<length; i++){
            printf("%.2d", (unsigned char)key[i]);
        }
    } else {
        for (int i=0; i<length; i++){
            printf("%.2x", (unsigned char)key[i]);
        }
    }

    printf("\n");
    return 0;
}