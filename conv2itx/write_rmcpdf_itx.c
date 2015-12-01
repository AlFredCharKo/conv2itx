//
//  write_rmcpdf_itx.c
//  conv2itx
//
//  Created by Alexander Kompch on 19.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "write_rmcpdf_itx.h"


int write_rmcpdf_itx(prms *pref, datatable *data) {
    int i = 0, j = 0, len1 = 0;
    FILE *FP = NULL;
    char *outfile = NULL;
    
    printf("\n***   IN write_rmcpdf_itx   ***\n");
    
        //  Make outfile string from pref->afilename
    len1 = (int)strlen(pref->afilename) + (int)strlen(IGORENDING);
    outfile = calloc((len1+1), sizeof(char));
    strcpy(outfile, pref->afilename);
    strcat(outfile, IGORENDING);
    
    printf("\noutfile: %s", outfile);
        
    FP = fopen(outfile, "w");
    if (FP == NULL) {
        printf("\nFile <%s> could not be opened! Will exit!", pref->afilename);
        exit(EXIT_FAILURE);
    }
    
    
        //  File header
    fprintf(FP, "IGOR");
    fprintf(FP, "\nX // pdfs from ***RMCXAS*** type written by conv2itx");
    fprintf(FP, "\nX // list of data files used:");
    for (i=0; i<pref->nfiles; i++) {
        fprintf(FP, "\nX // %s", pref->filelst[i]);
    }
    fprintf(FP,"\n");
    fprintf(FP,"X NewDataFolder/O/S root:%s\n", pref->afilename);
    
        // Wave names
    fprintf(FP, "WAVES/D/O");
    fprintf(FP, "%s\n", pdfWaveName(data->nColumns));
    fprintf(FP,"BEGIN\n");
    
        //Write data
    for (i = 0; i < data->nRows; i++) {
        for (j = 0; j < data->nColumns; j++) {
            fprintf(FP, "%13.6f ", data->x[m_elem(data, i, j)]);
        }
        fprintf(FP, "\n");
    }
    fprintf(FP, "\n");
    fprintf(FP, "END\n");
    
        //Write IGOR commands
    fprintf(FP, "X Preferences 0;Display g11 vs Rad as \"%s\"\n", pref->afilename);
    fprintf(FP, "%s\n", pdfAppendGraph(data->nColumns));
    fprintf(FP, "X EXAFS_pdf_def();Preferences 1\n");
    
    fclose(FP);
    free(outfile);
    return EXIT_SUCCESS;

}