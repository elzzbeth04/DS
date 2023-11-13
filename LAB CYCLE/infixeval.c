#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }

    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }

    return stack[top--];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int eval_post(char postfix[]) {
    int i = 0;
    int item;

    while ((item = postfix[i++]) != '#') {
        if (isdigit(item)) {
            push(item - '0');
        } else if (is_operator(item)) {
            int y = pop();
            int x = pop();
            int t;

            switch (item) {
                case '+':
                    t = x + y;
                    break;
                case '-':
                    t = x - y;
                    break;
                case '*':
                    t = x * y;
                    break;
                case '/':
                    t = x / y;
                    break;
            }

            push(t);
        }
    }

    return pop();
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter postfix expression (end with #): ");
    scanf("%s", postfix);

    int result = eval_post(postfix);

    printf("Result: %d\n", result);

    return 0;
}