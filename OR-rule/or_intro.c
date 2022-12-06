#include <string.h>

int or_intro(int l, char * buffer2[], char prefix[]){
    if (!strcmp(prefix,buffer2[l]))
        return 1;
    else 
        return 0;
}
