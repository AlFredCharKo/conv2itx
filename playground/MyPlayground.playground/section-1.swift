// Playground - noun: a place where people can play

int check_filetype(char* filen) {
    int type = 0;
    size_t suffixlen = 0, filenlen = 0;
    char *suffix = NULL;
    
    filenlen = strlen(filen);
    
    //check case 1
    suffixlen = strlen(SHIMADZUTXT);
    suffix = &filen[filenlen-suffixlen];
    if (strcmp(suffix, SHIMADZUTXT) == 0) type = 1;
    //check case 2
    suffixlen = strlen(RMCPDF);
    suffix = &filen[filenlen-suffixlen];
    if (strcmp(suffix, RMCPDF) == 0) type = 2;
    //check case 3
    suffixlen = strlen(RMCSPE)+1;
    suffix = &filen[filenlen-suffixlen];
    filen = strncpy(filen, suffix, suffixlen);
    if (strcmp(filen, RMCSPE) == 0) type = 3;
    //check case 4
    suffixlen = strlen(FEFFXMU);
    suffix = &filen[filenlen-suffixlen];
    if (strcmp(suffix, FEFFXMU) == 0) type = 4;
    
    
    return type;
}


