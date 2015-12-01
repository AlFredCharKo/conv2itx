//
//  countDoubleBlanksInLine.c
//  conv2itx
//
//  Created by Alexander Kompch on 28.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "countDoubleBlanksInLine.h"

int countDoubleBlanksInLine(const char* str) {
    
    size_t len = 0;
    const char *frontp = str;
    const char *endp = NULL;
    int nDblBlanks = 0;
    
    if( str == NULL ) { return -1; }
    if( str[0] == '\0' ) { return -1; }
    
    len = strlen(str);
    endp = str + len;
    
    while (*frontp != '\0') {
        if (*frontp == ' ') {
            frontp++;
            if (*frontp == ' ') {
                frontp++;
                if (*frontp != ' ') {
                    nDblBlanks++;
                } else {
                    frontp--;
                }
            }
        } else {
        frontp++;
        }
    }
    return nDblBlanks;
}
