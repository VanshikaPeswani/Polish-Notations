#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SS 100
#define MAX 100

int top_of_stack = -1;
char *pos, s[MAX];

void push(char a)
{
    s[++top_of_stack] = a;
}

char pop()
{
    if (top_of_stack == -1)
        return -1;
    else
        return s[top_of_stack--];
}

int precedence(char a)
{
    if (a == '(' || a == ')')
        return 0;
    if (a == '+' || a == '-')
        return 1;
    if (a == '*' || a == '/')
        return 2;
    if (a == '^')
        return 3;
}

void infixtoPostfix(char infix[])
{
    pos = infix;
    while (*pos != '\0')
    {
        if (isalnum(*pos))
            printf("%c", *pos);

        else if (*pos == '(')
            push(*pos);

        else if (*pos == ')')
        {
            while (((*pos) = pop()) != '(')
                printf("%c", (*pos));
        }

        else
        {
            while (precedence(s[top_of_stack]) >= precedence(*pos))
                printf("%c", pop());
            push(*pos);
        }

        pos++;
    }

    while (top_of_stack != -1)
        printf("%c", pop());
}