//
//  countBlanksInLine.c
//  conv2itx
//
//  Created by Alexander Kompch on 28.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//
//  counts the incurrences of sets of blanks separating / in between two sets of characters (a set can be one character long)

#include "countBlanksInLine.h"

int countBlanksInLine(const char* str) {
    
    size_t len = 0;
    const char *frontp = str;
    char *cpystr = NULL;
    int nColumns = 0;
    int i = 0;

    
    if( str == NULL ) { return -1; }
    if( str[0] == '\0' ) { return -1; }
    
        //make a copy of str to work with in function
    len = strlen(str);
    cpystr = calloc(len, sizeof(char));
    strcpy(cpystr, str);
    
        //remove blanks in beginning and at end of cpystr
    cpystr = trim(cpystr);
    frontp = cpystr;
    
//    printf("\ncpystr = [%s]", cpystr);
    
        //check for at least one blank in between any characters e.g. [X X] and count
    while (*frontp != '\0') {
        if (*frontp == ' ') {
            frontp++;
            continue;
        } else {        //frontp is NOT a blank
            if (*(frontp+1) == ' ') {       //*(frontp+1) IS a blank
                i = 2;
                while (*(frontp+i) == ' ') {i++;}   //skip any consecutive blanks
//                printf("\n*(frontp+i)=%s vs *(frontp+i+1)=%s", frontp+i, frontp+i+1);
                if (*(frontp+i) != '\0') {      //after blanks NOT YET EOL
                    nColumns++;
                    frontp = frontp + i;
                    continue;
                }
            } else {        //*(frontp+1) is NOT a blank
                frontp++;
                continue;
            }
        }
    }

    free(cpystr);
    return nColumns;
}
