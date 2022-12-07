/** @file modus_tollens.c
 *  @brief Contains definition for checking whether the Modus Tollens proof line is valid. 
 *  @bug No known bugs.
 */

/* -- Includes -- */

# include <string.h>
# include <stdio.h>
# include "../Misc/inf/infixToPrefix.h"

/** @brief Definition of modus_tollens() function
 *  \n Checks whether or not the Modus Tollens line in the proof is valid.
 * \n It works very similar to the imp_elim(), major differences are that negation is used and the comparison is changed, between given line and prefix of first line argument, and postfixes of second line and first line arguments for the appropriate length while also taking negation into account.
 */

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
