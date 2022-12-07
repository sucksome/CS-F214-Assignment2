/** @file imp_elim.c
 *  @brief Contains definition for checking whether the implies elimination proof line is valid. 
 *  @bug No known bugs.
 */

/* -- Includes -- */

#include "../AND-rule/and_elim.h"

/** @brief Definition of imp_elim() function
 *  \n Checks whether or not the implies elimination line in the proof is valid.
 * \n It uses and_elim() to compare the postfix of the argument with the postfix of the implication for the appropriate length and prefix of the first operand of the implication with the other suitable line argument given. 
 */
int imp_elim(int line,int l,int l2, char * buffer2[], char * buffer[]){
    if(and_elim('2',line,l,buffer2,buffer)){
        if (and_elim('1',l2,l,buffer2,buffer)){
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}
