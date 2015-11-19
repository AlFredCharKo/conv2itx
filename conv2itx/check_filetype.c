//
//  check_filetype.c
//  conv2itx
//
//  Created by Alexander Kompch on 17.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "check_filetype.h"


int check_filetype(const char* filen) {
    int type = -1;
    size_t suffixlen = 0, filenlen = 0;
    const char *suffix = NULL;
    char *filencpy = NULL;
    
    if (filen == NULL) {
        type = -1;
        return type;
    }
    
    filenlen = strlen(filen);
    filencpy = calloc(filenlen+1, sizeof(char));  //helper copy of filen for case 3
    
    
        //check case 1
    suffixlen = strlen(SHIMADZUTXT);
    if (filenlen >= suffixlen) {
        suffix = &filen[filenlen-suffixlen];
        if (strcmp(suffix, SHIMADZUTXT) == 0) type = 1;
    }

        //check case 2
    suffixlen = strlen(RMCPDF);
    if (filenlen >= suffixlen) {
        suffix = &filen[filenlen-suffixlen];
        if (strcmp(suffix, RMCPDF) == 0) type = 2;
    }

        //check case 3
    suffixlen = strlen(RMCSPE);
    if (filenlen >= suffixlen) {
        suffix = &filen[filenlen-suffixlen-2];  //2 additional characters for .1 as in rmc.spe.1
        filencpy = strncpy(filencpy, suffix, suffixlen);
        if (strcmp(filencpy, RMCSPE) == 0) type = 3;
    }
    
        //check case 4
    suffixlen = strlen(FEFFXMU);
    if (filenlen >= suffixlen) {
        suffix = &filen[filenlen-suffixlen];
        if (strcmp(suffix, FEFFXMU) == 0) type = 4;
    }
    
        //check case 99
    filencpy = strncpy(filencpy, filen, strlen(filen));
    if (strcmp(trim(filencpy), DUMMYFILE) == 0) type = 99;

    
    free(filencpy);
    return type;
}
