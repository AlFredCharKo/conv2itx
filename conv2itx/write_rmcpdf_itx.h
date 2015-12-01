//
//  write_rmcpdf_itx.h
//  conv2itx
//
//  Created by Alexander Kompch on 19.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __conv2itx__write_rmcpdf_itx__
#define __conv2itx__write_rmcpdf_itx__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "defs.h"
#include "trim.h"
#include "check_null.h"
#include "pdfWaveName.h"
#include "pdfAppendGraph.h" 
#include "m_elem.h"

int write_rmcpdf_itx(prms *pref, datatable *data);

#endif /* defined(__conv2itx__write_rmcpdf_itx__) */
