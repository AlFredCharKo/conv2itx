//
//  read_prmfile.h
//  conv2itx
//
//  Created by Alexander Kompch on 09.06.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __conv2itx__read_parfile__
#define __conv2itx__read_parfile__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "defs.h"
#include "check_null.h"
#include "trim.h"



prms* read_prmfile(char* prmfile);

#endif /* defined(__conv2itx__read_prmfile__) */
