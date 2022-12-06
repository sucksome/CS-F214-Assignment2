#include <string.h>

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
