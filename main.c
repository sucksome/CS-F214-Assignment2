#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int top = -1;

// checking if the stack is full
/** @brief Definition of isFull() function
 * @return Whether or not the stack is full
 */
int isFull(int lenInfix) {
    if(top == lenInfix - 1) return 1;
    else return 0;
} 

// checking if the stack is empty
/** @brief Definition of isEmpty() function
 * @return Whether or not the stack is empty
 */
int isEmpty() {
    if(top == -1) return 1;
    else return 0; 
}

// push function which inserts value in the stack and increments top
/** @brief Definition of push() function
 * @return Void
 */
void push(char item,int lenInfix,char * stack) {
    if (isFull(lenInfix)) return; 
	top++;
	stack[top] = item;
}

// pop function which removes an item from the stack and decrements top 
/** @brief Definition of pop() function
 * @return Pops the uppermost element of the stack if it is not empty
 */
int pop(char * stack) { 
    if (isEmpty()) return INT_MIN; 
        
    // decrements top and returns what has been popped      
    return stack[top--]; 
} 

/** @brief Definition of peek() function
 * @return Returns the topmost element of the stack if it is not empty
 */
int peek(char * stack){ 
    if (isEmpty()) return INT_MIN; 
    return stack[top];
} 

/** @brief Definition of checkIfOperand() function
 * @return Whether or not the character is a propositional atom
 */
// a function to check if the given character is a propositional atom 
int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
} 

/** @brief Definition of priority() function
 * @return Returns a priority value depending on the operator.
 */
// priority function to compare priority. It returns a larger value for a higher priority operator   
int priority(char ch) 
{ 
    switch(ch) {
        case '~':        
		return 5;
		break;

        case '*':    
		return 4;
		break;

		case '+':
		return 3;
		break;

        case '>':
        return 2;
        break;

		case '(':       
		case ')':
		return 1;
		break;
	}
    return -1; 
}

/** @brief Definition of getPostfix() function
 * 
 */
// getPostfix function to convert an infix expression to a postfix expression
int getPostfix(char* expression, char * stack, int lenInfix) 
{ 
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) 
    { 
        // we check whether the scanned character is an operand or not and add this to the output
        if (checkIfOperand(expression[i])) expression[++j] = expression[i]; 

        // we push '(' to the stack if we scan it
        else if (expression[i] == '(') push(expression[i],lenInfix,stack); 

        // if the scanned character is ')', we need to pop from the stack till '(' is encountered in the stack 
        else if (expression[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') expression[++j] = pop(stack);
            
            if (!isEmpty(stack) && peek(stack) != '(')return -1; // invalid expression              
            else pop(stack); 
        } 
        else // if the scanned character is an operator
        { 
            while (!isEmpty(stack) && priority(expression[i]) <= priority(peek(stack))) expression[++j] = pop(stack); 
            push(expression[i],lenInfix,stack); 
        } 

    } 

    // Once all inital expression characters are traversed, add all remaining elements to exp from stack
    while (!isEmpty(stack)) expression[++j] = pop(stack); 

    expression[++j] = '\0'; 
    
}

/** @brief Definition of reverse() function
 * @return Void
 */
// a function to reverse a string
void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}

/** @brief Definition of brackets() function
 * @return Void
 */
// a function to swap brackets
void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}

// the function to convert the infix expression into a prefix expression

/** @brief Definition of infixToPrefix() function
 *  @return The length of the infix expression
 */
int infixToPrefix(char *exp, char * stack, char * prefix, int lenInfix)
{

    int size = strlen(exp);

    // reverse string
    reverse(exp);
    // swap brackets
    brackets(exp);
    // get the postfix expression 
    getPostfix(exp,stack,lenInfix);
    // reverse the string again to get the prefix expression
    reverse(exp);
    strcpy(prefix,exp);
    return strlen(exp);
}

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
int and_elim(char mode, int line, int l, char * buffer2[], char * buffer[]){
    //printf("hi\n");
    int a = strlen(buffer2[line]);
    int b = strlen(buffer2[l]);
    //printf(":%s\n",((char *) *(buffer2+l))+1);
    //printf("%d,%d\n",line,l);
    //printf(":%s\n",buffer2[line]);
    //printf(":%s\n",buffer2[l]);
    if (mode == '1'){
        if(!strncmp(buffer2[l]+1,buffer2[line],a))
            return 1;
        else 
            return 0;
    }
    else {
        char str1[a+1];
        char str2[b+1];
        strcpy(str1,buffer2[line]);
        strcpy(str2,buffer2[l]);
        reverse(str1);
        reverse(str2);
        if(!strncmp(str1,str2,a))
            return 1;
        else 
            return 0;
    }
}
int or_intro(int l, char * buffer2[], char prefix[]){
    if (!strcmp(prefix,buffer2[l]))
        return 1;
    else 
        return 0;
}
int imp_elim(){}

int ln;

int checkline(int i, char * buffer[], char * buffer2[]){
  int index = 0, index2 = 0, temp = 0, min = 10;
  while(buffer[i][index]!='/'){
    index++;
    if(buffer[i][index]=='(')
      temp++;
    else if (buffer[i][index]==')')
      temp--;
    if (index!=0 && buffer[i][index+1]!='/' && (buffer[i][index]=='+' || buffer[i][index]=='*' || buffer[i][index]=='>')){
      if (temp<min){
        min=temp;
        if (buffer[i][index-1]=='(')
            index2=index+1;
        else
            index2=index;
      }
    }
  }
  index++;

  // printf("\n%c at index %d\n",buffer[i][index2],index2);
  

  if (buffer[i][index]=='P')
    return 1;

  char infix1[index2+1], prefix1[index2+1], stack1[index2+1];
  for (int t = 0; t < index2; t++){
      infix1[t]=buffer[i][t];
  }
  infix1[index2]='\0';

  char infix2[index-index2-1], prefix2[index-index2-1], stack2[index-index2-1];
  for (int t = 0; t < index-index2-2; t++){
      infix2[t]=buffer[i][index2+t+1];
  }
  infix2[index-index2-2]='\0';
  int len1 = infixToPrefix(infix1,stack1,prefix1,index2);
  int len2 = infixToPrefix(infix2,stack2,prefix2,index-2-index2);
  int r;
  if (buffer[i][index]=='*' && buffer[i][index+1]=='i')
    r = and_intro(i,(int) buffer[i][index+3] -49,(int) buffer[i][index+5] -49, prefix1, prefix2, buffer2);
  else if (buffer[i][index]=='*' && buffer[i][index+1]=='e')
    r = and_elim(buffer[i][index+2],i,(int) buffer[i][index+4] -49,buffer2,buffer);
  else if (buffer[i][index]=='+' && buffer[i][index+1]=='i'){
      if (buffer[i][index+2]=='1')
          r = or_intro((int) buffer[i][index+4] -49,buffer2,prefix1);
      else
          r = or_intro((int) buffer[i][index+4] -49,buffer2,prefix2);
  }
  else if (buffer[i][index]=='>' && buffer[i][index+1]=='e')
    return imp_elim();
  else
    r = 3;
  return r;
}

int check(char * buffer[],int n, char * buffer2[]){
  for (ln = 0; ln < n; ln++){
    int eval = checkline(ln,buffer,buffer2);
    if (eval == 0)
      return 0;
    else if (eval == 3)
      return 3;
  }
  return 1;
}

int main(){
  int n;      // number of lines in the proof
  printf("Enter number of statements: ");
  scanf("%d",&n);
  getchar();

  char * buffer[n];  // declaring buffer to store the lines in proof

  // loop to store each line of the proof 

  for (int line = 0; line < n; line++){
    int i = 0, j = 10;
    char ch;
    char * temp;
    temp = (char *) malloc(10*sizeof(char));

    while((ch=getchar())!='\n'){ 
        if(i>j-2){ 

            // Memory realloc if we're falling short

            temp = realloc(temp,(i+10)*sizeof(char)); 
            j = i+10; 
        }
        if(ch!='\b'){ 
            temp[i]=ch;    // Storing the input
            i++; 
        }
        else 
            i--;    // A backspace character was used
      }
      temp[i]='\0';
      buffer[line] = temp;
  }

  char * buffer2[n];
  for (int line = 0; line < n; line++){
      int inx = 0;
      while (buffer[line][inx]!='/'){
          inx++;
      }
      char inf[inx+1], stk[inx+1];
      char * prf = (char *) malloc((inx+1)*sizeof(char));
      for (int h = 0; h < inx; h++){
          inf[h]=buffer[line][h];
      }
      inf[inx]='\0';
      int lex = infixToPrefix(inf,stk,prf,inx+1);
      buffer2[line]=prf;
  }

  int result = check(buffer,n,buffer2);
  if (result == 0)
    printf("Invalid Proof\n");
  else if (result == 1)
    printf("Valid Proof\n");
  else if (result == 3)
    printf("Invalid Proof due to undefined proof rule at Line %d\n",ln+1);
  return 0;
}
