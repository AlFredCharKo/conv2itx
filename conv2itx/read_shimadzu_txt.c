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
    int line = 0, ct = 0;
    int i=0, n= 0, max = 0;
    double sum = 0.0;
    printf("\n");
    data = calloc(1, sizeof(datatable));

//calloc for +1 to store average of data
    data->x = calloc(((2 * temp->nfiles) + 1), sizeof(double*));

    for (i=0; i<temp->nfiles; i++) {
        FP=fopen(temp->filelst[i], "rt");
            //        printf("\nread_shimadzu: temp->filelst[%d]=%s",i,temp->filelst[i]);
        check_null(FP, "read_shimadzu_txt - cannot open file");

        ct = 0;
        line = 0;
        while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
            line ++;
            if (!strncmp("#", buffer, 1)) {
                ct++;
            }
        }
        //header lines to skip in spec files -> .txt
        //are 2 and do not start with '#'
        temp->ndata[i] = line - ct - 2;
        if (temp->ndata[i]>max) {
            max = temp->ndata[i];
        }

        fclose(FP);
  
    }

    temp->max = max;
    
    //average spalte als letzte
    data->x[((2 * temp->nfiles))] = calloc(temp->max, sizeof(double));

    
    for (i=0; i<temp->nfiles; i++) {

//allocate space for data
        data->x[2*i] = calloc(temp->max, sizeof(double));
        printf("2*i = %d calloc\n", 2*i);
        if (data->x[2*i] == NULL) {
            printf("\nin read_data: calloc %d * %lu for data->x[%d] failed: Will Exit!", temp->ndata[i], sizeof(double), 2*i);
            return NULL;
        }
        data->x[2*i+1] = calloc(temp->max, sizeof(double));
        printf("2*i+1 = %d calloc\n", 2*i+1);
        if (data->x[2*i+1] == NULL) {
            printf("\nin read_data: calloc %d * %lu for data->x[%d] failed: Will Exit!", temp->ndata[i], sizeof(double), 2*i+1);
            return NULL;
        }
        
        FP=fopen(temp->filelst[i], "rt");
        if (FP == NULL) {
            printf("\n***   read_data:Could not open <%s>.", temp->filelst[i]);
            return NULL;
        }
        line = 0;
        n = 0;

        while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
            line++;
            if (line > 2) {
//                n++;
                buffer_ptr=trim(buffer_ptr);
                buffer_ptr=repl_comma(buffer_ptr);
                sscanf(buffer, "%lf %lf", &data->x[2*i][n], &data->x[2*i+1][n]);
//                if (fabs(data->x[2*i+1][n]) < 1E-3) {
//                    n--;
//                }
  //              printf("line: %03d: data: %s gelesen als: <%f> <%f>\n",n, buffer, data->x[2*i][n], data->x[2*i+1][n]);
                n++;
            }
        }
        temp->max = n;
        fclose(FP);
    }
    for (n=0; n<max; n++) {
        sum = 0.0;
        for (i=0; i<temp->nfiles; i++) {
            sum = sum + data->x[2*i+1][n];
  //          printf("\nsum(%d)=%f",n, sum);
        }
        data->x[((2 * temp->nfiles))][n] = sum / (double)temp->nfiles;
    }
    
    free(buffer_ptr);
    return data;
}