#include <stdio.h>
#include <string.h>
#define MAX 500
char stack[MAX];
int top=0;
void push(char a)
{
    stack[top]=a;
    top=top+1;
   // printf("pushing %c\n",a);

}
void pop()
{
    top--;
    //printf("poping");
}

int isempty()
{
    if(top<=0)
        return 1;
    else
        return 0;
}
int isCorrect(char *str)
{   top=0;
    int i=0;

    while(str[i]!='\0')
    {
       if(str[i]=='(')
       {
           push('(');
           i++;
           continue;
       }
       else if(str[i]=='{')
       {
           push('{');
           i++;
           continue;
       }
       else if(str[i]=='[')
       {
           push('[');
           i++;
           continue;
       }


        else if(str[i]==')')
       {
           while(stack[top-1]!='(' && !isempty())
           {
              //  printf("while poping ( \n");
               pop();
           }
           if(isempty())
           {
              // printf("stack is empty");
               return 0;
           }
               else if(stack[top-1]=='(')
               pop();
       }
        else if(str[i]=='}')
       {
            while(stack[top-1]!='{' && !isempty())
             {
                //printf("while poping { \n");
               pop();
           }
           if(isempty())
               return 0;
            else if(stack[top-1]=='{')
               pop();
       }
        else if(str[i]==']')
       {
           while(stack[top-1]!='[' && !isempty())
            {
               // printf("while poping [ \n");
               pop();
           }
           if(isempty())
               return 0;
           else if(stack[top-1]=='[')
               pop();
       }

        i++;
    }

   if(isempty())
        return 1;
    else
        return 0;
}
int main() {
    char str[MAX];
    int T, i;
    scanf("%d", &T);
    for(i = 0; i < T; i++) {
        scanf("%s", str);
        if(isCorrect(str) == 1) {
            printf("YES");
        } else {
            printf("NO");
        }
        printf("\n");
    }
    return 0;
}
