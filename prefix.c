#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "postfix.c"
#define SS 100
#define MAX 100

int t = -1;
char prefix[MAX], s[MAX];


void infixtoPrefix(char infix2[])
{
    int len = strlen(infix2);

    for (int i = len - 1; i >= 0; i--)
    {
        if (isalnum(infix2[i]))
            prefix[++t] = (infix2[i]);

        else if (infix2[i] == ')')
            push(infix2[i]);

        else if (infix2[i] == '(')
        {
            while (((infix2[i]) = pop()) != ')')
                prefix[++t] = (infix2[i]);
        }

        else
        {
            while (precedence(s[top_of_stack]) > precedence(infix2[i]))
                prefix[++t] = pop();

            push(infix2[i]);
        }
    }

    while (top_of_stack != -1)
        prefix[++t] = pop();
}