//
//  count_lines_with_keychar.h
//  conv2itx
//
//  Created by Alexander Kompch on 19.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#ifndef __conv2itx__count_lines_with_keychar__
#define __conv2itx__count_lines_with_keychar__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "check_null.h"
#include "trim.h"

int count_lines_to_keyword(const char* filename, int startline, const char keychar);

#endif /* defined(__conv2itx__count_lines_with_keychar__) */
