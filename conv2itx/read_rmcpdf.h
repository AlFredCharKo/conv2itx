//
//  read_rmcpdf.h
//  conv2itx
//
//  Created by Alexander Kompch on 19.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __conv2itx__read_rmcpdf__
#define __conv2itx__read_rmcpdf__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "defs.h"
#include "trim.h"
#include "check_null.h"
#include "countBlanksInLine.h"
#include "m_elem.h"

datatable* read_rmcpdf(prms* temp);

#endif /* defined(__conv2itx__read_rmcpdf__) */
