//
//  read_xmudat.h
//  conv2itx
//
//  Created by Alexander Kompch on 01.12.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __conv2itx__read_xmudat__
#define __conv2itx__read_xmudat__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "defs.h"
#include "trim.h"
#include "check_null.h"
#include "m_elem.h"
#include "count_lines_with_keychar.h"
#include "countBlanksInLine.h"

datatable* read_xmudat(prms* temp);

#endif /* defined(__conv2itx__read_xmudat__) */
