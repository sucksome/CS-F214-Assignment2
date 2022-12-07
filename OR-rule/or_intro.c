/** @file or_intro.c
 *  @brief Contains definition for checking whether the or introduction proof line is valid. 
 *  @bug No known bugs.
 */

/* -- Includes -- */

#include <string.h> //For using the strcmp function

int or_intro(int l, char * buffer2[], char prefix[]){
    if (!strcmp(prefix,buffer2[l]))
        return 1;
    else 
        return 0;
}
