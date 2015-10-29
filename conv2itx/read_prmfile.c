//
//  read_prmfile.c
//  fftchi
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "read_prmfile.h"

prms* read_prmfile(char* prmfile)
{
    int i = 0, line=0;
    char buffer[MAX_LEN];
    char *buffer_ptr=buffer;
    prms* pref = (prms *)malloc(sizeof(prms));
    pref->outfile = NULL;
    pref->filelst = NULL;
    pref->prmfile = NULL;
    FILE *FP;
    
    FP=fopen(prmfile, "rt");
    if (FP == NULL) {
        printf("\n***   read_prmfile:Could not open <%s>.", prmfile);
        return NULL;
    }
    
    pref->prmfile = calloc((strlen(prmfile)+1), sizeof(char));
    strcpy(pref->prmfile, prmfile);
    
    while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        line ++;
        if (line == 1) {
            sscanf(buffer, "%d", &(pref->nfiles));
            pref->filelst = calloc(pref->nfiles, sizeof(*pref->filelst));
            for (i=0; i<pref->nfiles; i++) {
                buffer_ptr = fgets(buffer, MAX_LEN, FP);
                buffer_ptr=trim(buffer_ptr);
                pref->filelst[i] = calloc((strlen(buffer_ptr)+1), sizeof(char));
                strcpy(pref->filelst[i], buffer_ptr);
                line++;
            }
            continue;
        } else if (line == (2 + pref->nfiles)) {
            buffer_ptr=trim(buffer_ptr);
            pref->meannm = calloc((strlen(buffer_ptr)+1), sizeof(char));
            strcpy(pref->meannm, buffer_ptr);
        } else if (line == (3 + pref->nfiles)) {
            buffer_ptr=trim(buffer_ptr);
            pref->outfile = calloc((strlen(buffer_ptr)+1), sizeof(char));
            strcpy(pref->outfile, buffer_ptr);
        }
    }
    
    pref->ndata = calloc(pref->nfiles, sizeof(int));
    
    fclose(FP);
    FP = NULL;
    return pref;
}

/*

 typedef struct {
 int nfiles;
 char** filelst;
 char* meannm;
 char* outfile;
 //the following are not read from parfile
 int* ndata;
 int max;
 char* prmfile;
 } prms;
 
 typedef struct {
 double** x;
 } datatable;
*/