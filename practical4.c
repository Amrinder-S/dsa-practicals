#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
int stack[max];
int top = -1;

int is_operand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void push(char ch) {
    if (top >= max - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top < 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int is_empty() {
    return top < 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    int i, j;
    char ch;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (is_operand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!is_empty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!is_empty() && peek() != '(') {
                printf("Unbalanced parentheses\n");
                return;
            } else {
                pop();
            }
        } else {
            while (!is_empty() && precedence(ch) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (!is_empty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int is_balanced(char postfix[]) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] == '(') {
            push(postfix[i]);
        } else if (postfix[i] == ')') {
            if (is_empty() || pop() != '(') {
                return 0;
            }
        }
    }
    return is_empty();
}

int evaluate_postfix(char postfix[]) {
    int i, x, y;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (is_operand(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            y = pop();
            x = pop();
            switch (postfix[i]) {
                case '+':
                    push(x + y);
                    break;
                case '-':
                    push(x - y);
                    break;
                case '*':
                    push(x * y);
                    break;
                case '/':
                    push(x / y);
                    break;
                case '^':
                    push(x ^ y);
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
        }
    }
    return pop();
}

int main() {
    char infix[max], postfix[max];
int choice;
do {
printf("\nMenu\n");
printf("1. Convert infix to postfix\n");
printf("2. Evaluate postfix expression\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter infix expression: ");
scanf("%s", infix);
infix_to_postfix(infix, postfix);
printf("Postfix expression: %s\n", postfix);
if (is_balanced(postfix)) {
printf("Balanced parentheses\n");
} else {
printf("Unbalanced parentheses\n");
}
break;
case 2:
printf("Enter postfix expression: ");
scanf("%s", postfix);
if (is_balanced(postfix)) {
printf("Result: %d\n", evaluate_postfix(postfix));
} else {
printf("Unbalanced parentheses\n");
}
break;
case 3:
printf("Exiting...\n");
break;
default:
printf("Invalid choice\n");
break;
}
} while (choice != 3);
return 0;
}