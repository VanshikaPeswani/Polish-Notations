#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "prefix.c"
#define SS 100
#define MAX 100

char infix[MAX], infix2[MAX];

int main()
{
    printf("\nEnter the valid infix expression : ");
    gets(infix);
    strcpy(infix2, infix);
    printf("\nInfix : %s", infix);
    printf("\n\nPostfix: ");
    infixtoPostfix(infix);
    infixtoPrefix(infix2);
    printf("\nPrefix: %s", strrev(prefix));
    return 0;
}
