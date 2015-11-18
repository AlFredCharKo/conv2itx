//
//  main.c
//  conv2itx
//
//  Created by Alexander Kompch on 04.09.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "main.h"

int main(int argc, const char* argv[]) {

    prms *pref=NULL;
    datatable *data=NULL;
    char *prmfile=NULL;
    int i = 0;
    
    prmfile = check_cmd_args(argc, argv);
    check_null(prmfile, "main - prmfile");
    
    printf("\n***   main: parfile=%s",prmfile);
    
    pref=read_prmfile(prmfile);
    check_null(pref, "main - pref");
    
    print_prms(pref);
    
    do_files(pref);


    
    
    
//    data = read_shimadzu_txt(pref);
//    write_shimadzu_itx(pref, data);
    


    free(data);
    free(pref->outfile);
    free(pref->prmfile);
    free(pref->ndata);
    for (i=0; i<pref->nfiles; i++) {
        free(pref->filelst[i]);
    }
    free(pref->filelst);
    free(pref);


    
    printf("\n");
    return EXIT_SUCCESS;
}

