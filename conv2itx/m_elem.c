//
//  m_elem.c
//  conv2itx
//
//  Created by Alexander Kompch on 29.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "m_elem.h"


int m_elem(const datatable* m, uint row, uint column) {
    if (m == NULL) {
        printf("\nm_elem: 2D-array does not exist in memory. Will exit!\n");
        exit(EXIT_FAILURE);
    } else if (column >= m->nColumns) {
        printf("\nm_elem: %d columns is more than allocated. Will exit!\n", column);
        exit(EXIT_FAILURE);
    } else if (row >= m->nRows) {
        printf("\nm_elem: %d rowss is more than allocated. Will exit!\n", row);
        exit(EXIT_FAILURE);
    }
    
    return row * m->nColumns + column;
}