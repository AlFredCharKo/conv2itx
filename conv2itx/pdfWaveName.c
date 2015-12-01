//
//  pdfWaveName.c
//  conv2itx
//
//  Created by Alexander Kompch on 30.11.15.
//  Copyright (c) 2015 Alexander Kompch. All rights reserved.
//

#include "pdfWaveName.h"

const char* pdfWaveName(int i) {
    int npdf = 0;
    
    const char *wavenamestr[9];
    wavenamestr[0] = "\tRad,\tg11,\tint_g11";
    wavenamestr[1] = "\tRad,\tg11,\tint_g11,\tg12,\tint_g12";
    wavenamestr[2] = "\tRad,\tg11,\tint_g11,\tg12,\tint_g12,\tg13,\tint_g13";
    wavenamestr[3] = "\tRad,\tg11,\tint_g11,\tg12,\tint_g12,\tg13,\tint_g13,\tg14,\tint_g14";
    wavenamestr[4] = "\tRad,\tg11,\tint_g11,\tg12,\tint_g12,\tg22,\tint_g22";
    wavenamestr[5] = "\tRad,\tg11,\tint_g11,\tg12,\tint_g12,\tg13,\tint_g13,\tg22,\tint_g22,\tg23,\tint_g23";
    wavenamestr[6] = "\tRad,\tg11,\tint_g11,\tg12,\tint_g12,\tg13,\tint_g13,\tg14,\tint_g14,\tg22,\tint_g22,\tg23,\tint_g23,\tg24,\tint_g24";
    wavenamestr[7] = "\tRad,\tg11,\tint_g11,\tg12,\tint_g12,\tg13,\tint_g13,\tg22,\tint_g22,\tg23,\tint_g23,\tg33,\tint_g33";
    wavenamestr[8] = "\tRad,\tg11,\tint_g11,\tg12,\tint_g12,\tg13,\tint_g13,\tg14,\tint_g14,\tg22,\tint_g22,\tg23,\tint_g23,\tg24,\tint_g24,\tg33,\tint_g33,\tg34,\tint_g34";

    if ((i - 1) % 2 == 0) {
        npdf = (i - 1) / 2;     //determine # of pdfs from i
    } else {
        printf("\nNumber of columns in *.pdf file matches no combination of possible ntyp/nspec values! return NULL!");
        return NULL;
    }
    
    printf("\nnpdf = %d", npdf);
    switch (npdf) {
        case 1:
            return wavenamestr[0];
            break;
        case 2:
            return wavenamestr[1];
            break;
        case 3:
            return wavenamestr[4];
            break;
        case 4:
            return wavenamestr[3];
            break;
        case 5:
            return wavenamestr[5];
            break;
        case 6:
            return wavenamestr[7];
            break;
        case 7:
            return wavenamestr[6];
            break;
        case 9:
            return wavenamestr[8];
            break;
        default:
            return NULL;
            break;
    }

    return NULL;
}
