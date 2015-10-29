//
//  main.c
//  fftchi
//
//  Created by Alexander Kompch on 04.09.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[]) {
    char *prmfile=NULL;
    prms *pref=NULL;
    datatable *data=NULL;
    int i = 0;
    
    printf("\n***   main:argc=%d", argc);
    if (argc < 2) {
        prmfile=calloc((strlen(DEFPARFILE)+1), sizeof(char));
        if (prmfile == NULL) {
            printf("\n***   main: malloc prmfile failed");
            return EXIT_FAILURE;
        }
        printf("\n***   main: strlen('DEFPARFILE')*sizeof(char)=%zu",strlen(DEFPARFILE)*sizeof(char));
        strcpy(prmfile,DEFPARFILE);
    } else {
        prmfile=calloc((strlen(argv[1])+1), sizeof(char));
        if (prmfile == NULL) {
            printf("\n***   main: malloc prmfile failed");
            return EXIT_FAILURE;
        }
        printf("\n***   main: strlen(argv[1])*sizeof(char)=%zu",strlen(argv[1])*sizeof(char));
        strcpy(prmfile,argv[1]);
    }
    
    printf("\n***   main: parfile=%s",prmfile);
    pref=read_prmfile(prmfile);
    if (pref == NULL) {
        printf("\n***   main: read_prmfile failed! Will exit!");
        exit(EXIT_FAILURE);
    }
    free(prmfile);
    
    data = read_data(pref);
    
    print_prms(pref);
    
    write_itx(pref, data);
    


    free(data);
    free(pref->outfile);
    free(pref->prmfile);
    free(pref->ndata);
    for (i=0; i<pref->nfiles; i++) {
        free(pref->filelst[i]);
    }
    free(pref->filelst);
    free(pref);


    
    printf("\n");
    return EXIT_SUCCESS;
}

