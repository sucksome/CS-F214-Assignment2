# include <string.h>
# include <stdio.h>
# include "../Misc/inf/infixToPrefix.h"

int modus_tollens(int line, int l, int l2,char * buffer2[],char * buffer[]){
    if (buffer2[line][0]=='~' && buffer2[l][0] == '>' && buffer2[l2][0] == '~') {
        int p = strlen(buffer2[line]) -1;
        int pp = strlen(buffer2[l]) -1 -p;
        int np = strlen(buffer2[l]);
        if (!strncmp(buffer2[line]+1,buffer2[l]+1,p)){
            char str1[pp+1];
            char str2[np+1];
            strcpy(str1,buffer2[l2]+1);
            strcpy(str2,buffer2[l]);
            reverse(str1);
            reverse(str2);
            if(!strncmp(str1,str2,pp))
                return 1;
            else 
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}
