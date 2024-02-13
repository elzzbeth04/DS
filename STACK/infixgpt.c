#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }

    stack[++top] = value;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }

    return stack[top--];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
        if (op== '^')
        return 3;
    return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    int i = 0;
    int j = 0;

    while (infix[i] != '\0') {

        if (infix[i] >= 'a' && infix[i] <= 'z')
         {
            postfix[j++] = infix[i++];
            } 
            else if (is_operator(infix[i])) 
            {
                  while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                   {
                        postfix[j++] = pop();
                    }
                push(infix[i++]);
            } 
        else if (infix[i] == '(')
         {
              push(infix[i++]);
            } 
            else if (infix[i] == ')')
             {
                while (top != -1 && stack[top] != '(') 
                {
                    postfix[j++] = pop();
                }
                if (top != -1 && stack[top] == '(') 
                {
                pop();
                }
            i++;
            }
         else
          {
            printf("Invalid character in infix expression\n");
            return;
            }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    gets(infix); // Note: gets() is used here for simplicity. In real code, consider using fgets().

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
