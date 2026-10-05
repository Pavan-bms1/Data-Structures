#include<stdio.h>
#include<string.h>
#define max 100
char s[max];
int top=-1;
int pf(char symbol)
{
    switch(symbol)
    {
      case '+':
      case '-':return 2;
      case '*':
      case '/':return 4;
      case '$':
      case '^':return 5;
      case '(':
      case ')':return 0;
      case '#':return -1;
      default:return 8;
    }
}
int gf(char symbol)
{
    switch(symbol)
    {
      case '+':
      case '-':return 1;
      case '*':
      case '/':return 3;
      case '$':
      case '^':return 6;
      case '(':return 9;
      case ')':return 0;
      case '#':return 0;
      default:return 7;
    }
}
int main()
{
    int symbol,j=-1;
    char infix[50],postfix[50];
    s[++top]='#';
    printf("Enter any infix expression:");
    scanf("%s",infix);
    int i=0;
    while(infix[i]!='\0')
    {
        symbol=infix[i];
        while(pf(s[top])>gf(symbol))
        {
            postfix[++j]=s[top--];
        }
        if(pf(s[top])!=gf(symbol))
        {
            s[++top]=symbol;
        }
        else{
            top--;
        }
        i++;
    }
    while(top!=-1){
        postfix[++j]=s[top--];
    }
    i=0;
    postfix[++j]='\0';
    printf("The postfix expression is:\n");
    printf("%s",postfix);
    return 0;
}
