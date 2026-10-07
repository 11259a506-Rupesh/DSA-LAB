#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][100];
int top = -1;

void push(char str[])
{
    strcpy(stack[++top], str);
}

void pop(char str[])
{
    strcpy(str, stack[top--]);
}

int main()
{
    char postfix[100];
    char op1[100], op2[100], temp[100];
    int i;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))
        {
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(temp);
        }
        else
        {
            pop(op2);
            pop(op1);

            printf(temp, "(%s%c%s)", op1, postfix[i], op2);
            push(temp);
        }
    }

    printf("Infix expression: %s\n", stack[top]);

    return 0;
}
