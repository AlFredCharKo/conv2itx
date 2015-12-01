//
//  read_shimadzu_txt.c
//  conv2itx
//
//  Created by Alexander Kompch on 07.09.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "read_shimadzu_txt.h"

datatable* read_shimadzu_txt(prms* temp) {
    datatable* data = NULL;
    FILE* FP;
    char buffer[MAX_LEN];
    char *buffer_ptr = buffer;
    int line = 0;
    int i=0, n= 0, max = 0;
    double sum = 0.0;
    printf("\n");
    data = calloc(1, sizeof(datatable));

    for (i=0; i<temp->nfiles; i++) {
        FP=fopen(temp->filelst[i], "rt");
        check_null(FP, "read_shimadzu_txt - cannot open file");
        
        line = 0;
        while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
            line ++;
        }
        
        //header lines to skip in spec files -> .txt
        //are 2 and do not start with '#'
        temp->ndata[i] = line - 2;
        if (temp->ndata[i]>max) {
            max = temp->ndata[i];
        }
        fclose(FP);
    }

    temp->max = max;
    
    data->x=calloc(((2 * temp->nfiles) + 1) * max, sizeof(double));
    check_null(data->x, "read_shimadzu_txt - data->x[2*temp->nfiles]");
    data->nRows = max;
    data->nColumns = (2 * temp->nfiles) + 1;

    
    for (i=0; i<temp->nfiles; i++) {
        FP=fopen(temp->filelst[i], "rt");
        check_null(FP, "read_shimadzu_txt - cannot open file");
        line = 0;
        n = 0;

        while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
            line++;
            if (line > 2) {
                buffer_ptr=trim(buffer_ptr);
                buffer_ptr=repl_comma(buffer_ptr);
                sscanf(buffer, "%lf %lf", &data->x[m_elem(data, n, 2*i)], &data->x[m_elem(data, n, 2*i+1)]);
                n++;
            }
        }
        temp->max = n;
        fclose(FP);
    }
    
        //sum up and average per row for last column
    for (n=0; n<max; n++) {
        sum = 0.0;
        for (i=0; i<temp->nfiles; i++) {
            sum = sum + data->x[m_elem(data, n, 2*i+1)];
        }
        data->x[m_elem(data, n, 2 * temp->nfiles)] = sum / (double)temp->nfiles;
    }
    
    free(buffer_ptr);
    return data;
}