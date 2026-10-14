#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][100];
int top = -1;

int main() {
    char postfix[100];
    int i;
    char op1[100], op2[100], temp[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            top++;
            stack[top][0] = postfix[i];
            stack[top][1] = '\0';
        } else {
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);

            sprintf(temp, "(%s%c%s)", op1, postfix[i], op2);

            top++;
            strcpy(stack[top], temp);
        }
    }

    printf("Infix expression: %s\n", stack[top]);

    return 0;
}