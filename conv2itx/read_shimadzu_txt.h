//
//  read_shimadzu_txt.h
//  conv2itx
//
//  Created by Alexander Kompch on 07.09.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __conv2itx__read_shimadzu_txt__
#define __conv2itx__read_shimadzu_txt__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"
#include "defs.h"
#include "check_null.h"
#include "trim.h"
#include "repl_comma.h"

datatable* read_shimadzu_txt(prms* temp);
#endif /* defined(__conv2itx__read_shimadzu_txt__) */
