//
//  structs.h
//  conv2itx
//
//  Created by Alexander Kompch on 04.09.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef conv2itx_structs_h
#define conv2itx_structs_h

#include "defs.h"

//typedefstructs
typedef struct {
//    char* infile;
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

typedef struct {
    char nmu[CNML + 1];
    char nmv[CNML + 1];
    char nmw[CNML + 1];
    char nmx[CNML + 1];
    char nmy[CNML + 1];
    int ndata;
    int ndata_lim;
    char dattyp[4];
    datatable *dat;
} datfilestruct;




#endif
