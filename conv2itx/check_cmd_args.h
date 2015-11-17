//
//  check_cmd_args.h
//  conv2itx
//
//  Created by Alexander Kompch on 17.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __conv2itx__check_cmd_args__
#define __conv2itx__check_cmd_args__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "structs.h"
#include "check_null.h"

char* check_cmd_args(int argCount, const char*  argArray[]);

#endif /* defined(__conv2itx__check_cmd_args__) */
