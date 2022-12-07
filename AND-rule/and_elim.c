/** @file and_elim.c
 *  @brief Contains definition for checking whether the and elimination proof line is valid. 
 *  @bug No known bugs.
 */

/* -- Includes -- */

#include <string.h> //For using the strlen, strncmp and strcpy functions
#include "../Misc/inf/infixToPrefix.h"

/** @brief Definition of and_elim() function
 *  \n Checks whether or not the and elimination line in the proof is valid.
 */
int and_elim(char mode, int line, int l, char * buffer2[], char * buffer[]){
    int a = strlen(buffer2[line]);
    int b = strlen(buffer2[l]);
    if (mode == '1'){
        if(!strncmp(buffer2[l]+1,buffer2[line],a))
            return 1;
        else 
            return 0;
    }
    else if (mode == '2'){
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
    else {
        return 0;
    }
}
