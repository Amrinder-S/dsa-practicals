#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

int stack[max];
int top = -1;

void push(int ch) { stack[++top] = ch; }
int pop() { return stack[top--]; }
int is_empty() { return top < 0; }

int is_operand(char ch) { return isalnum(ch); }
int precedence(char ch) { return ch == '+' || ch == '-' ? 1 : ch == '*' || ch == '/' ? 2 : ch == '^' ? 3 : -1; }

void infix_to_postfix(char infix[], char postfix[]) {
    int i, j;
    for (i = 0, j = 0; infix[i]; i++) {
        char ch = infix[i];
        if (is_operand(ch)) { postfix[j++] = ch; }
        else if (ch == '(') { push(ch); }
        else if (ch == ')') { while (!is_empty() && stack[top] != '(') { postfix[j++] = pop(); } pop(); }
        else {
            while (!is_empty() && precedence(ch) <= precedence(stack[top])) { postfix[j++] = pop(); }
            push(ch);
        }
    }
    while (!is_empty()) { postfix[j++] = pop(); }
    postfix[j] = '\0';
}

int is_balanced(char postfix[]) {
    int i;
    for (i = 0; postfix[i]; i++) {
        if (postfix[i] == '(') { push(postfix[i]); }
        else if (postfix[i] == ')') { if (is_empty() || pop() != '(') { return 0; } }
    }
    return is_empty();
}

int evaluate_postfix(char postfix[]) {
    int i;
    for (i = 0; postfix[i]; i++) {
        char ch = postfix[i];
        if (is_operand(ch)) { push(ch - '0'); }
        else {
            int y = pop(), x = pop();
            switch (ch) { case '+': push(x + y); break; case '-': push(x - y); break;
                case '*': push(x * y); break; case '/': push(x / y); break; case '^': push(x ^ y); break; }
        }
    }
    return pop();
}

int main() {
    char infix[max], postfix[max];
    int choice;
    do {
        printf("\nMenu\n1. Convert infix to postfix\n2. Evaluate postfix expression\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infix_to_postfix(infix, postfix);
                printf("Postfix expression: %s\n", postfix);
                printf(is_balanced(postfix) ? "Balanced parentheses\n" : "Unbalanced parentheses\n");
                break;
            case 2:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                printf(is_balanced(postfix) ? "Result: %d\n" : "Unbalanced parentheses\n", evaluate_postfix(postfix));
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
