#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/' || c == '%')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;
    char c;

    printf("Enter infix: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            stack[++top] = c;
        }
        else if (c == ')')
        {
            while (stack[top] != '(')
                postfix[j++] = stack[top--];

            top--;
        }
        else
        {
            // Left-to-right associativity
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = stack[top--];
            }

            stack[++top] = c;
        }
    }

    while (top != -1)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';

    printf("Postfix: %s", postfix);

    return 0;
}