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
    int ncases;
    int nfiles;
    char** filelst;
    char* meannm;
    char** outfiles;
    //the following are not read from parfile
    int* ndata;
    int max;
    char* afilename;
    char* prmfile;
} prms;

typedef struct {
    int nColumns;
    int nRows;
    double* x;
} datatable;

#endif
