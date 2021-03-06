//
//  do_files.h
//  conv2itx
//
//  Created by Alexander Kompch on 17.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __conv2itx__do_files__
#define __conv2itx__do_files__

#include <stdio.h>
#include "defs.h"
#include "structs.h"
#include "print_prms.h"
#include "check_filetype.h"
#include "read_shimadzu_txt.h"
#include "write_shimadzu_itx.h"
#include "read_rmcpdf.h"
#include "write_rmcpdf_itx.h"
#include "read_rmcspe.h"
#include "write_rmcspe_itx.h"
#include "read_xmudat.h"
#include "write_xmudat_itx.h"

void do_files(prms *pref);

#endif /* defined(__conv2itx__do_files__) */
