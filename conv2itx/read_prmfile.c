//
//  read_prmfile.c
//  conv2itx
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
    check_null(pref, "read_prmfile - pref");
    pref->outfiles = NULL;
    pref->filelst = NULL;
    pref->prmfile = NULL;
    FILE *FP;
    
    FP=fopen(prmfile, "rt");
    check_null(FP, "read_prmfile - cannot open file");

    
    pref->prmfile = calloc((strlen(prmfile)+1), sizeof(char));
    check_null(pref->prmfile, "read_prmfile - pref->prmfile");
    strcpy(pref->prmfile, prmfile);
    
    while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        line ++;
        if (line == 1) {
            sscanf(buffer, "%d", &(pref->ncases));
            pref->outfiles = calloc(pref->ncases, sizeof(*pref->outfiles));
            check_null(pref->outfiles, "read_prmfile - pref->outfiles");
            continue;
        } else if (line == 2) {
            sscanf(buffer, "%d", &(pref->nfiles));
            pref->filelst = calloc(pref->nfiles, sizeof(*pref->filelst));
            check_null(pref->filelst, "read_prmfile - pref->filelst");
            for (i=0; i<pref->nfiles; i++) {
                buffer_ptr = fgets(buffer, MAX_LEN, FP);
                buffer_ptr=trim(buffer_ptr);
                pref->filelst[i] = calloc((strlen(buffer_ptr)+1), sizeof(char));
                check_null(pref->filelst[i], "read_prmfile - pref->filelst[i]");
                strcpy(pref->filelst[i], buffer_ptr);
                line++;
            }
            continue;
        } else if (line == (3 + pref->nfiles)) {
            buffer_ptr=trim(buffer_ptr);
            pref->meannm = calloc((strlen(buffer_ptr)+1), sizeof(char));
            check_null(pref->meannm, "read_prmfile - pref->meannm");
            strcpy(pref->meannm, buffer_ptr);
            continue;
        } else if (line == (4 + pref->nfiles)) {
            for (i=0; i<pref->ncases; i++) {
                buffer_ptr=trim(buffer_ptr);
                pref->outfiles[i] = calloc((strlen(buffer_ptr)+1), sizeof(char));
                check_null(pref->outfiles[i], "read_prmfile - pref->outfiles[i]");
                strcpy(pref->outfiles[i], buffer_ptr);
                buffer_ptr = fgets(buffer, MAX_LEN, FP);
                line++;
                }
            break;
            }
        }
    
    pref->ndata = calloc(pref->nfiles, sizeof(int));
    check_null(pref->ndata, "read_prmfile - pref->ndata");
    
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