//
//  count_lines_to_keyword.c
//  conv2itx
//
//  Created by Alexander Kompch on 19.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//
//  returns the number of lines between startline and the first occurence of keyword in filename
//  the first line in a file is counted as 1
//  the keyword actually appears in line = (startline+return value of this function)
//  return 0 means keyword is in startline
//  returns -1 if keyword not found in part after startline
//  startline < 1 will be set to startline = 1
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
    
    if (startline < 1) {
        startline = 1;
    }
    
    for (i = 1; i <= startline; i++) {      //fast forward to startline including startline; first line in file counted as 1
        buffer_ptr = fgets(buffer, MAX_LEN, FP);
        check_null(buffer_ptr, "count_lines_to_keyword - premature end of file");
        line++;
    }
    
    
    while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        line ++;
        if (strncmp(keyword, trim(buffer_ptr), strlen(keyword)) == 0) {
            count = line - startline - 1;   //get strictly number of lines BETWEEN startline and keywordline
            fclose(FP);
            return count;
        }
    }

    fclose(FP);
    return count;
}
