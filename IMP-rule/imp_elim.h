/*! \file imp_elim.h
    \brief A documented header file
    
    Contains declaration for imp_elim()
*/
/*! \fn imp_elim(int line,int l,int l2, char * buffer2[], char * buffer[])
    \brief Checks the validity of an implies elimination proof line 
    \param line The line number of the proof line
    \param l1 The first line argument
    \param l2 The second line argument
    \param buffer2 The buffer consisting of prefix expressions
    \param buffer The buffer consisting of infix expressions
*/

int imp_elim(int line,int l,int l2, char * buffer2[], char * buffer[]);
