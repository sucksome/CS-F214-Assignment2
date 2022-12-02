#include <stdio.h>
#include <stdlib.h>

int and_intro(){}
int and_elim(){}
int or_intro(){}
int imp_elim(){}

int ln;

int checkline(int i, char * buffer[]){
  int index = 0;
  while(buffer[i][index]!='/'){
    index++;
  }
  index++;
  if (buffer[i][index]=='P')
    return 1;
  else if (buffer[i][index]=='*' && buffer[i][index+1]=='i')
    return and_intro();
  else if (buffer[i][index]=='*' && buffer[i][index+1]=='e')
    return and_elim();
  else if (buffer[i][index]=='+' && buffer[i][index+1]=='i')
    return or_intro();
  else if (buffer[i][index]=='>' && buffer[i][index+1]=='e')
    return imp_elim();
  else
    return 3;
}

int check(char * buffer[],int n){
  for (ln = 0; ln < n; ln++){
    int eval = checkline(ln,buffer);
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

  int result = check(buffer,n);
  if (result == 0)
    printf("Invalid Proof\n");
  else if (result == 1)
    printf("Valid Proof\n");
  else if (result == 3)
    printf("Invalid Proof due to undefined proof rule at Line %d\n",ln+1);
  return 0;
}
