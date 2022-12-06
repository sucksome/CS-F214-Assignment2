// A simple a tool for verifying whether a certain proof of a given sequent is valid or not 

/* -- Includes -- */

/* libc includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* custom headers */
#include "Misc/inf/infixToPrefix.h"
#include "AND-rule/and_intro.h"
#include "AND-rule/and_elim.h"
#include "OR-rule/or_intro.h"
#include "IMP-rule/imp_elim.h"
#include "MT/modus_tollens.h"

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
  int cou=0,cou2=0;
  for (int lol = 0; lol < index-1; lol++){
      if(buffer[i][lol]=='('){
          if(lol<index2)
              cou++;
          else if (lol>index2)
              cou2--;
      }
      else if (buffer[i][lol]==')'){
          if(lol<index2)
              cou--;
          else if (lol>index2)
              cou2++;
      }
  }
  char infix1[index2+1-cou], prefix1[index2+1-cou], stack1[index2+1-cou];
  for (int t = cou; t < index2; t++){
          infix1[t-cou]=buffer[i][t];
  }
  infix1[index2-cou]='\0';

  char infix2[index-index2-1-cou2], prefix2[index-index2-1-cou2], stack2[index-index2-1-cou2];
  for (int t = 0; t < index-index2-2-cou2; t++){
      infix2[t]=buffer[i][index2+t+1];
  }
  infix2[index-index2-2-cou2]='\0';
  int len1 = infixToPrefix(infix1,stack1,prefix1,index2-cou);
  int len2 = infixToPrefix(infix2,stack2,prefix2,index-2-index2-cou2);
  int r;
  if (buffer[i][index2]=='*' && buffer[i][index]=='*' && buffer[i][index+1]=='i')
    r = and_intro(i,(int) buffer[i][index+3] -49,(int) buffer[i][index+5] -49, prefix1, prefix2, buffer2);
  else if (buffer[i][index]=='*' && buffer[i][index+1]=='e')
    r = and_elim(buffer[i][index+2],i,(int) buffer[i][index+4] -49,buffer2,buffer) && (buffer2[ (int) buffer[i][index+4] -49][0]=='*');
  else if (buffer[i][index2]=='+' && buffer[i][index]=='+' && buffer[i][index+1]=='i'){
      if (buffer[i][index+2]=='1')
          r = or_intro((int) buffer[i][index+4] -49,buffer2,prefix1);
      else
          r = or_intro((int) buffer[i][index+4] -49,buffer2,prefix2);
  }
  else if (buffer[i][index]=='>' && buffer[i][index+1]=='e')
    r = imp_elim(i,(int) buffer[i][index+3] -49,(int) buffer[i][index+5] -49,buffer2,buffer) && (buffer2[(int) buffer[i][index+3] -49][0]=='>');
  else if (buffer[i][index]=='M' && buffer[i][index+1]=='T')
    r = modus_tollens(i,(int) buffer[i][index+3] -49, (int) buffer[i][index+5] -49,buffer2,buffer);
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
  char * buffer2[n];

  // loop to store each line of the proof 

  for (int line = 0; line < n; line++){
    int i = 0, j = 10;
    char ch;
    char * temp;
    temp= (char *) malloc(10*sizeof(char));
    int inx = 0;
    while((ch=getchar())!='\n'){ 
        if(i>j-2){ 
            temp = realloc(temp,(i+10)*sizeof(char));       // Memory realloc if we're falling short 
            j = i+10; 
        }
        if(ch!='\b'){ 
            temp[i]=ch;    // Storing the input
            i++; 
        }
        else 
            i--;    // A backspace character was used
        if (ch =='/' && inx==0){
            inx=i-1;
        }
    }
    temp[i]='\0';
    buffer[line] = temp;
    char stk[inx+1], inf[inx+1];
    strncpy(inf,temp,inx);
    inf[inx]='\0';
    char * prf = (char *) malloc((inx+1)*sizeof(char));
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
  for (int y = 0; y < n; y++){
      free(buffer[y]);
      free(buffer2[y]);
  }
  printf("**\tMemory Freed\t**\n");
  return 0;
}
