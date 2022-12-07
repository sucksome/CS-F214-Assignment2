/** @file and_intro.c
 *  @brief Contains definition for checking whether the and introduction proof line is valid. 
 *  @bug No known bugs.
 */

/* -- Includes -- */

#include <string.h> //For using the strcmp function

/** @brief Definition of and_intro() function
 *  \n Checks whether or not the and introduction line in the proof is valid.
 */

int and_intro(int line, int l1, int l2, char prefix1[], char prefix2[], char * buffer2[]){
    if (l1 >= line || l2 >= line)
        return 0;
    if (strcmp(prefix1,buffer2[l1])==0){
        if(strcmp(prefix2,buffer2[l2])==0){
            return 1;
        }
    }
    return 0;
}
