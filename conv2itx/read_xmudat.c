//
//  read_xmudat.c
//  conv2itx
//
//  Created by Alexander Kompch on 01.12.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "read_xmudat.h"

datatable* read_xmudat(prms* temp) {
    datatable *data = NULL;
    FILE* FP;
    char buffer[MAX_LEN];
    char *buffer_ptr = buffer;
    int readFileNumber = 0;
    int nColumns = 0;
    int line = 0, headerlines= 0;
    int col = 0, cur = 0, read = 0;
    
    check_null(temp, "read_xmudat - no parameters");
    
        //find number of headerlines by counting lines starting with '#'
    headerlines = count_lines_with_keychar(temp->filelst[readFileNumber], 1, '#');
    
    FP=fopen(temp->filelst[readFileNumber], "rt");
    check_null(FP, "read_xmudat - cannot open file");
    
        //skip headerlines and read first line after that
    for (line=1; line<=headerlines+1; line++) {
        buffer_ptr = fgets(buffer, MAX_LEN, FP);
    }
        //count number of columns in this line
    nColumns = countBlanksInLine(buffer_ptr) + 1;
    
        //read until EOF to count rows/lines in file
    while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        line ++;
    }
    
    
        //    callocate memory for a datatable of size datable.x[column=nColumns][row=line]
    data = calloc(1, sizeof(datatable));
    data->nColumns = nColumns;
    data->nRows = line-headerlines-1;
    data->x = calloc(data->nColumns * data->nRows, sizeof(double));
    
    temp->ndata = calloc(1, sizeof(int));
    temp->ndata[0]=data->nRows;
    temp->max=data->nRows;
    
        //rewind file to actually read in data
    rewind(FP);
    line = 0;
        //skip headerlines
    for (line=1; line<=headerlines; line++) {
        buffer_ptr = fgets(buffer, MAX_LEN, FP);
    }
        //read data with first line after headers as line # 0
        //cur moves the position in buffer_ptr to skip already read characters
    line=0;
    while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        line++;
        col = 0;
        cur = 0;
        buffer_ptr=trim(buffer_ptr);
            //        printf("line=%d:[%s]\n", line, buffer_ptr);
        for (col=0; col<data->nColumns; col++) {
            if (sscanf(buffer_ptr+cur, "%lf%n", &data->x[m_elem(data, line-1, col)], &read) != 1) {
                printf("read_xmudat - sscanf error of xmu.dat in line %d\n and col %d", line, col);
                return NULL;
            }
            cur += read;
        }
    }
    
    fclose(FP);
    return data;
}