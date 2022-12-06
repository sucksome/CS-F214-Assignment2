#include "../AND-rule/and_elim.h"

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
