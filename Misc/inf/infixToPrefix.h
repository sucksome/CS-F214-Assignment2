/*! \file infixToPrefix.h
    \brief A documented header file
    
    Contains declaration for infixToPrefix()
*/
/*! \fn  int infixToPrefix(char * exp, char * stack, char * prefix, int lenInfix)
    \brief Reads \a exp and generates it's prefix which is written to \a prefix . 
    \param exp The input string of infix expression
    \param stack The stack for in-function operations
    \param prefix The output string
    \param lenInfix Length of the infix expression
    \return Returns length of \a prefix.
*/
int infixToPrefix(char * exp, char * stack, char * prefix, int lenInfix);
void reverse();
