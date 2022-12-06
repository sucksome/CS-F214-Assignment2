#include <string.h>
#include "../Misc/inf/infixToPrefix.h"

int and_elim(char mode, int line, int l, char * buffer2[], char * buffer[]){
    int a = strlen(buffer2[line]);
    int b = strlen(buffer2[l]);
    if (mode == '1'){
        if(!strncmp(buffer2[l]+1,buffer2[line],a))
            return 1;
        else 
            return 0;
    }
    else {
        char str1[a+1];
        char str2[b+1];
        strcpy(str1,buffer2[line]);
        strcpy(str2,buffer2[l]);
        reverse(str1);
        reverse(str2);
        if((!strncmp(str1,str2,a)) && str2[a]!='~' && str2[a]!='*' && str2[a]!='>' && str2[a]!='+')
            return 1;
        else 
            return 0;
    }
}
