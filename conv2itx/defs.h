//
//  defs.h
//  conv2itx
//
//  Created by Alexander Kompch on 04.09.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef conv2itx_defs_h
#define conv2itx_defs_h

#define MAX_LEN 999                     //Maximum number of characters to read with fgets
#define CNML 20                         //Length of the column name labe
#define DEFPARFILE "read2itx.par"       //Default parameter file to open, if none given on command line
#define IGORENDING ".itx"               //Output file ending. .itx files are automatically opened with IGOR
#define DUMMYFILE "dummy.file"          //DUMMYFILE is used to separate files from consecutive treatment
                                        //The following are SUFFIXES (files in pref->filelst will be ID'ed by these SUFFIXES) of filenames for identifying the file format and corresponding routines
#define SHIMADZUTXT ".txt"
#define RMCPDF "rmc.pdf"
#define RMCSPE "rmc.spe"
#define FEFFXMU "xmu.dat"


#endif
