//
//  print_prms.c
//  conv2itx
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "print_prms.h"

int print_prms(prms* pref)
{
    int i = 0;
    
    printf("\n***   IN print_pars   ***\n");
    
    printf("\nprmfile: %s", pref->prmfile);
    printf("\nnumber of data files to read: %3d", pref->nfiles);
    for (i=0; i<pref->nfiles; i++) {
        printf("\ndata file #%3d: %s contains %3d data points", i+1, pref->filelst[i], pref->ndata[i]);
    }
    printf("\nndata max: %3d", pref->max);
    if (pref->ncases > 0) {
        printf("\nnumber of output files: %3d", pref->ncases);
        for (i=0; i<pref->ncases; i++) {
            printf("\noutput filen #%3d: %s", i+1, pref->outfiles[i]);
        }
    }

    printf("\n");
    return EXIT_SUCCESS;
}