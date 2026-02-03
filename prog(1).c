#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push 
void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

// Pop 
char pop() {
    if (top != -1) {1
        return stack[top--];
    }
    return '\0';
}

// Check matching pair
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Function to check balance
int isBalanced(char expr[]) {
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // If opening bracket, push
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1)
                return 0;

            char popped = pop();
            if (!isMatching(popped, ch))
                return 0;
        }
    }
    return (top == -1);
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    fgets(expr, MAX, stdin);

    if (isBalanced(expr))
        printf("Expression has balanced parentheses.\n");
    else
        printf("Expression does NOT have balanced parentheses.\n");

    return 0;
}
