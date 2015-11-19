//
//  count_lines_with_keychar.c
//  conv2itx
//
//  Created by Alexander Kompch on 19.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//
//  returns the number of lines that start with keychar in filename counting from startline
//  the first line in a file is counted as 1
//  returns -1 if keychar not found in startline
//  startline < 1 will be set to startline = 1
//  exits if filename has less than startline lines
#include "count_lines_with_keychar.h"

int count_lines_with_keychar(const char* filename, int startline, const char keychar){
    int i = 0;
    int count = -1;
    char buffer[MAX_LEN];
    char *buffer_ptr = buffer;
    FILE *FP = NULL;
    
    FP=fopen(filename, "rt");
    check_null(FP, "count_lines_with_keychar - cannot open file");
    
    if (startline < 1) {
        startline = 1;
    }
    
    for (i = 1; i < startline; i++) {
        buffer_ptr = fgets(buffer, MAX_LEN, FP);
        check_null(buffer_ptr, "count_lines_with_keychar - premature end of file");
    }
    
    if ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        if (strncmp(&keychar, trim(buffer_ptr), 1) == 0) {      //check in startline
            count = 1;
        } else {
            fclose(FP);
            return -1;                                          //keychar not found at beginning of startline -> return -1
        }
    }

    while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        if (strncmp(&keychar, trim(buffer_ptr), 1) == 0) {      //check following lines after startline
            count++;
        } else {
            fclose(FP);
            return count;
        }
    }
    
    fclose(FP);
    return count;
}