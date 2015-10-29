//
//  read_chidat.h
//  fftchi
//
//  Created by Alexander Kompch on 07.09.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __fftchi__read_chidat__
#define __fftchi__read_chidat__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"
#include "defs.h"
#include "trim.h"
#include "repl_comma.h"

datatable* read_data(prms* pref);
#endif /* defined(__fftchi__read_chidat__) */
