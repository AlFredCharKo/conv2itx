//
//  pdfAppendGraph.c
//  conv2itx
//
//  Created by Alexander Kompch on 30.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "pdfAppendGraph.h"

const char* pdfAppendGraph(int i) {
    int npdf = 0;
    
    const char *appendstr[9];
    appendstr[0] = "X AppendToGraph int_g11 vs Rad";
    appendstr[1] = "X AppendToGraph int_g11,g12,int_g12 vs Rad";
    appendstr[2] = "X AppendToGraph int_g11,g12,int_g12,g13,int_g13 vs Rad";
    appendstr[3] = "X AppendToGraph int_g11,g12,int_g12,g13,int_g13,g14,int_g14 vs Rad";
    appendstr[4] = "X AppendToGraph int_g11,g12,int_g12,g22,int_g22 vs Rad";
    appendstr[5] = "X AppendToGraph int_g11,g12,int_g12,g13,int_g13,g22,int_g22,g23,int_g23 vs Rad";
    appendstr[6] = "X AppendToGraph int_g11,g12,int_g12,g13,int_g13,g14,int_g14,g22,int_g22,g23,int_g23,g24,int_g24 vs Rad";
    appendstr[7] = "X AppendToGraph int_g11,g12,int_g12,g13,int_g13,g22,int_g22,g23,int_g23,g33,int_g33 vs Rad";
    appendstr[8] = "X AppendToGraph int_g11,g12,int_g12,g13,int_g13,g14,int_g14,g22,int_g22,g23,int_g23,g24,int_g24,g33,int_g33,g34,int_g34 vs Rad";
    
    npdf = (i - 1) / 2;     //determine # of pdfs from i

    
    printf("\nnpdf = %d", npdf);
    switch (npdf) {
        case 1:
            return appendstr[0];
            break;
        case 2:
            return appendstr[1];
            break;
        case 3:
            return appendstr[4];
            break;
        case 4:
            return appendstr[3];
            break;
        case 5:
            return appendstr[5];
            break;
        case 6:
            return appendstr[7];
            break;
        case 7:
            return appendstr[6];
            break;
        case 9:
            return appendstr[8];
            break;
        default:
            return NULL;
            break;
    }
    
    return NULL;;

    
}