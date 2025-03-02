/*Data Structure and Algorithm project
Infix to Postfix Notation using stack*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000

char stack_str[MAX];
int top=-1;


int precedence(char c)
{
    if(c=='(')
        return 0;
    else if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
}

void push(char c)
{
    stack_str[++top]=c;
}

char pop()
{
    return stack_str[top--];
}

void Postfix(char s[])
{
    int l=strlen(s);

    for(int i=0;i<l;i++)
    {
        if(isdigit(s[i])||isalpha(s[i]))
        {
            printf("%c",s[i]);
        }
        else if(s[i] == '(')
        {
            push(s[i]);
        }
        else if(s[i]==')')
        {
            while(stack_str[top]!= '(')
                printf("%c",pop());
            pop();//4 xtra '('
        }
        else
        {
            while(top!=-1&&precedence(stack_str[top])>=precedence(s[i]))
                printf("%c",pop());
            push(s[i]);
        }
    }

    while (top!=-1)
        printf("%c",pop());
}

int main()
{
    freopen("input.txt","r",stdin);
    char s[MAX];
    printf("Enter infix expression : ");
    scanf("%s",s);
    printf("%s",s);
    printf("\n\nPostfix expression : ");
    Postfix(s);
    printf("\n\n");

    return 0;
}
