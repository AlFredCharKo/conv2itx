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
    int sumofcases = -1;
    datatable *data = NULL;
    prms *temp = NULL;

    
    for (i=0; i<pref->nfiles; i++) {
        switch (check_filetype(pref->filelst[i])) {
            case 1:
                    //Shimadzu file
                sumofcases++;
                temp = calloc(1, sizeof(prms));
                temp->filelst = (char **)calloc(pref->nfiles, sizeof(*pref->filelst));//make a temporary prms structure with the needed info to read, convert and write
                check_null(temp->filelst, "do_files - case 1 temp->filelst");
                
                temp->filelst[0] = pref->filelst[i];
                j=i+1;  //check next file and following as long as filetype == 1
                while (j < pref->nfiles && check_filetype(pref->filelst[j]) == 1) {
                    temp->filelst[j-i] = pref->filelst[j];
                    j++;
                }
                temp->nfiles = j-i;
                    //allocate more of the temp struct
                temp->ndata = calloc(temp->nfiles, sizeof(int));
                check_null(temp->ndata, "do_files - temp->ndata");
                temp->meannm = pref->meannm;
                temp->afilename = pref->outfiles[sumofcases];
                
                i=j-1;  //set i as if it had counted through the files itself
                data = read_shimadzu_txt(temp);
                print_prms(temp);
                write_shimadzu_itx(temp, data);
                    //end freeing every part of temp struct again, except for where the pointer from pref was copied!!!
                free(data->x);
                free(data);
                free(temp->filelst);
                free(temp->ndata);
                free(temp);
                break;
            case 2:
                    //rmc.pdf file
                sumofcases++;
                
                temp = calloc(1, sizeof(prms));
                check_null(temp, "do_files - case 2 temp");
                
                temp->filelst = (char **)calloc(1, sizeof(*pref->filelst));
                check_null(temp->filelst, "do_files - case 2 temp->filelst");
                
                temp->filelst[0] = pref->filelst[i];
                temp->nfiles = 1;
                temp->afilename = pref->outfiles[sumofcases];
                
                data = read_rmcpdf(temp);
                print_prms(temp);
                write_rmcpdf_itx(temp, data);
                free(data->x);
                free(data);
                free(temp->filelst);
                free(temp->ndata);
                free(temp);
                break;
            case 3:
                    //rmc.spe file
                sumofcases++;
                
                temp = calloc(1, sizeof(prms));
                check_null(temp, "do_files - case 2 temp");
                
                temp->filelst = (char **)calloc(1, sizeof(*pref->filelst));
                check_null(temp->filelst, "do_files - case 3 temp->filelst");
                
                temp->filelst[0] = pref->filelst[i];
                temp->nfiles = 1;
                temp->afilename = pref->outfiles[sumofcases];
                
                data = read_rmcspe(temp);
                print_prms(temp);
                write_rmcspe_itx(temp, data);
                free(data->x);
                free(data);
                free(temp->filelst);
                free(temp->ndata);
                free(temp);
                break;
            case 4:
                    //xmu.dat file
                sumofcases++;
                
                temp = calloc(1, sizeof(prms));
                check_null(temp, "do_files - case 2 temp");
                
                temp->filelst = (char **)calloc(1, sizeof(*pref->filelst));
                check_null(temp->filelst, "do_files - case 3 temp->filelst");
                
                temp->filelst[0] = pref->filelst[i];
                temp->nfiles = 1;
                temp->afilename = pref->outfiles[sumofcases];
                
                data = read_xmudat(temp);
                print_prms(temp);
                write_xmudat_itx(temp, data);
                free(data->x);
                free(data);
                free(temp->filelst);
                free(temp->ndata);
                free(temp);
                break;
            case 99:
                    //dummy.file file
                break;
            case -1:
                    //check_filetype did not find a match
                printf("\ndo_files: check_filetype - no match!");
                break;
            default:
                    //this case  does not exist
                printf("\ndo_files: check_filetype - default case called!");
                break;
        }

    }
    
    
    
    
    
}
