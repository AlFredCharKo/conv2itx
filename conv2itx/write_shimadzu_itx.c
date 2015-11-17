//
//  write_shimadzu_itx.c
//  conv2itx
//
//  Created by Alexander Kompch on 10.09.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "write_shimadzu_itx.h"
    
int write_shimadzu_itx(prms *pref, datatable *data) {
    
    int i = 0, n = 0, len1 = 0;
    FILE *FP = NULL;
    char *outfile = NULL;
    
    printf("\n***   IN write_itx   ***\n");

//  Make outfile string from pref->outfile
    len1 = (int)strlen(pref->outfile) + (int)strlen(IGORENDING);
    outfile = calloc((len1+1), sizeof(char));
    strcpy(outfile, pref->outfile);
    strcat(outfile, IGORENDING);
    
    printf("\noutfile: %s", outfile);

    
    FP = fopen(outfile, "w");
    if (FP == NULL) {
        printf("\nFile <%s> could not be opened! Will exit!", pref->outfile);
        exit(EXIT_FAILURE);
    }
    
    
    //  File header
    fprintf(FP, "IGOR\n");
    fprintf(FP, "X // written by read2itx\n");
//    fprintf(FP, "X // dattyp:%s\n", chidatf->dattyp);
    fprintf(FP,"\n");
    fprintf(FP,"X NewDataFolder/O/S root:%s\n", pref->meannm);

    // Wava names
    fprintf(FP, "WAVES/D/O");
    for (n=0; n<pref->nfiles; n++) {
        if (n < pref->nfiles-1) {
            fprintf(FP,"\tlambda_%03d,\ttrans_%03d,",n+1,n+1);
        } else if (n == pref->nfiles-1) {
            fprintf(FP,"\tlambda_%03d,\ttrans_%03d,\t%s", n+1, n+1, pref->meannm);
        }
    }
    fprintf(FP,"\n");
    fprintf(FP,"BEGIN\n");

    

    
    //  Write data as ((2 * pref->nfiles) + 1) columns
    for (n=0; n<pref->max; n++) {
        for (i=0; i<pref->nfiles; i++) {

            fprintf(FP,"%20.6f %20.6f", data->x[2*i][n], data->x[2*i+1][n]);
        }
        fprintf(FP,"%20.6f\n", data->x[((2 * pref->nfiles))][n]);

    }
    fprintf(FP, "END\n");
    fprintf(FP, "X Preferences 0;Display trans_001 vs lambda_001 as \"%s\"\n", pref->meannm);
    for (n=2; n<pref->nfiles; n++) {
        fprintf(FP, "X AppendToGraph trans_%03d vs lambda_%03d\n", n, n);
    }
    
    fprintf(FP, "X AppendToGraph trans_%03d vs lambda_%03d\n", n, n);
    fprintf(FP, "X AppendToGraph %s vs lambda_001;DelayUpdate\n", pref->meannm);
    fprintf(FP, "X NPPT_pres();Preferences 1\n");

    fclose(FP);
    free(outfile);
    return EXIT_SUCCESS;
}
