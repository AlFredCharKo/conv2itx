//
//  read_rmcspe.c
//  conv2itx
//
//  Created by Alexander Kompch on 01.12.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "read_rmcspe.h"

datatable* read_rmcspe(prms* temp) {
    datatable *data = NULL;
    FILE* FP;
    char buffer[MAX_LEN];
    char *buffer_ptr = buffer;
    int readFileNumber = 0;
    int nColumns = 0;
    int line = 0;
    int i = 0;
    
    check_null(temp, "read_rmcspe - no parameters");
    
    FP=fopen(temp->filelst[readFileNumber], "rt");
    check_null(FP, "read_rmcspe - cannot open file");
    
    if ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) == NULL) {
        printf("\nread_rmcspe: file is empty");
        return NULL;
    }
    
    
    nColumns = countBlanksInLine(buffer_ptr) + 1;
    
    line = 1;
    while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        line ++;
    }
    
    
        //    callocate memory for a datatable of size datable.x[column=nColumns][row=line]
    data = calloc(1, sizeof(datatable));
    data->nColumns = nColumns;
    data->nRows = line;
    data->x = calloc(nColumns * line, sizeof(double));
    
    temp->ndata = calloc(1, sizeof(int));
    temp->ndata[0]=data->nRows;
    temp->max=data->nRows;
    
    rewind(FP);
    line = 0;
    
    for (line = 0; line < data->nRows; line++) {
        for (i = 0; i < nColumns; i++) {
            fscanf(FP, "%lf", &data->x[m_elem(data, line, i)]);
        }
    }
    
    fclose(FP);
    return data;
}
