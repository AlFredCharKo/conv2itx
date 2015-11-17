//
//  repl_comma.c
//  conv2itx
//
//  Created by Alexander Kompch on 18.10.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "repl_comma.h"


char *repl_comma(char *str) {
    
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;
    
    if( str == NULL ) { return NULL; }
    if( str[0] == '\0' ) { return str; }
    
    len = strlen(str);
    endp = str + len;
    
    while (*frontp != '\0') {
        ++frontp;
        if (*frontp == ',') {
            *frontp = '.';
        }
    }
    return str;
}
