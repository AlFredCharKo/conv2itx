//
//  check_null.c
//  conv2itx
//
//  Created by Alexander Kompch on 17.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "check_null.h"

void check_null(void* ptr, char errortxt[]) {
    
    if (ptr == NULL) {
        printf("\nNULL pointer ecountered: %s",errortxt);
        printf("\nWill EXIT!\n");
        exit(EXIT_FAILURE);
    }

}