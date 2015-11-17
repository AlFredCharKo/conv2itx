//
//  do_files.c
//  conv2itx
//
//  Created by Alexander Kompch on 17.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "do_files.h"


void do_files(prms *pref) {
        //goes through all files in pref->filelst and calls corresponding read_file and then write_file_itx routine
        //if shimadzu_txt file is encountered, all immeadiately following shimadzu_txt files will be read, averaged and written
        //to handle multiple sets of shimadzu_txt files, use dummy.file as seperating filename in filelst
    int i = 0, j = 0;
    int ntxtfiles = 0;
    
    datatable *data = NULL;
    
    
    
    for (i=0; i<pref->nfiles; i++) {
        switch (check_filetype(pref->filelst[i])) {
            case 1:
                    //Shimadzu file
                j=i+1;  //check next file and following as long as filetype == 1
                while (check_filetype(pref->filelst[j]) == 1) {
                    j++;
                }
                ntxtfiles = j-i;
                i=j-1;
                data = read_shimadzu_txt(ntxtfiles, filenames)
                write_shimadzu_itx(data, outfile, columnnames)
                free(data);
                break;
            case 2:
                    //rmc.pdf file
                data = read_rmcpdf(filename)
                write_rmcpdf_itx(data, outfile)
                free(data);
                break;
            case 3:
                    //rmc.spe file
                data = read_rmcspe(filename)
                write_rmcspe_itx(data, outfile, spen)
                free(data);
                break;
            case 4:
                    //xmu.dat file
                data = read_xmudat(filename)
                write_xmudat_itx(data, outfile)
                free(data);
                break;
            default:
                    //this case  does not exist
                printf("\ndo_files: check_filetype - default case called!");
                break;
        }

    }
    
    
    
    
    
}
