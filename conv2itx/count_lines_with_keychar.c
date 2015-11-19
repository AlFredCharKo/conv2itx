//
//  count_lines_with_keychar.c
//  conv2itx
//
//  Created by Alexander Kompch on 19.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//
//  returns the number of lines that start with keychar in filename counting from startline
//  returns -1 if keychar not found in startline
//  exits if filename has less than startline lines
#include "count_lines_with_keychar.h"

int count_lines_to_keyword(const char* filename, int startline, const char keychar){
    int i = 0;
    int count = -1;
    char buffer[MAX_LEN];
    char *buffer_ptr = buffer;
    FILE *FP = NULL;
    
    FP=fopen(filename, "rt");
    check_null(FP, "count_lines_with_keychar - cannot open file");
    
    for (i = 0; i < startline; i++) {
        buffer_ptr = fgets(buffer, MAX_LEN, FP);
        check_null(FP, "count_lines_with_keychar - premature end of file");
    }
    
    
    while ((buffer_ptr = fgets(buffer, MAX_LEN, FP)) != NULL) {
        while (strncmp(&keychar, trim(buffer_ptr), 1) == 0) {
            count++;
        }
    }
    
    
    return count;
}