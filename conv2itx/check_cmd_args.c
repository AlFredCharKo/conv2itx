//
//  check_cmd_args.c
//  conv2itx
//
//  Created by Alexander Kompch on 17.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "check_cmd_args.h"



char* check_cmd_args(int argCount, const char*  argArray[]) {
    
    char *arg=NULL;


    printf("\n***   check_cmd_args:argc=%d", argCount);
    if (argCount <= 1) {        //<=1 means no arguments: fallback to default parameter file name
        arg=calloc((strlen(DEFPARFILE)+1), sizeof(char));
        check_null(arg, "check_cmd_args - arg");
        printf("\n***   check_cmd_args: strlen('DEFPARFILE')*sizeof(char)=%zu",strlen(DEFPARFILE)*sizeof(char));
        strcpy(arg,DEFPARFILE);
    } else {                //else means 1 command line argument or more, read first argument into arg, ignore rest
        arg=calloc((strlen(argArray[1])+1), sizeof(char));
        check_null(arg, "check_cmd_args - arg");
        printf("\n***   check_cmd_args: strlen(argv[1])*sizeof(char)=%zu",strlen(argArray[1])*sizeof(char));
        strcpy(arg,argArray[1]);
    }

    return arg;
}