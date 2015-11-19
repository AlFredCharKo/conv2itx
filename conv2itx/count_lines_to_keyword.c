//
//  count_lines_to_keyword.c
//  conv2itx
//
//  Created by Alexander Kompch on 19.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//
//  returns the number of lines between startline and the first occurence of keyword in filename
//  returns -1 if keyword not found
//  exits if filename has less than startline lines
#include "count_lines_to_keyword.h"

int count_lines_to_keyword(const char* filename, int startline, const char* keyword) {
    int i = 0;
    int count = -1, line = 0;
    char buffer[MAX_LEN];
    char *buffer_ptr = buffer;
    FILE *FP = NULL;
    
    FP=fopen(filename, "rt");
    check_null(FP, "count_lines_to_keyword - cannot open file");
    
    for (i = 0; i < startline; i++) {
        buffer_ptr = fgets(buffer, MAX_LEN, FP);
        check_null(FP, "count_lines_to_keyword - premature end of file");
        line++;
    }
    
    
    while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        line ++;
        if (strncmp(keyword, trim(buffer_ptr), strlen(keyword)) == 0) {
            count = line - startline;
            return count;
        }
    }


    return count;
}
