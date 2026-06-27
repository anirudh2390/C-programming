#include <stdio.h>
#include <ctype.h>
#include <math.h>

int stack[100];
int top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int main() {
    char exp[100], *e;
    int n1, n2, n3, num;
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    e = exp;
    
    while (*e != '\0') {
        if (isdigit(*e)) {
            num = *e - '0';
            push(num);
        } else {
            n2 = pop();
            n1 = pop();
            switch (*e) {
                case '+': n3 = n1 + n2; break;
                case '-': n3 = n1 - n2; break;
                case '*': n3 = n1 * n2; break;
                case '/': n3 = n1 / n2; break;
                case '^': n3 = pow(n1, n2); break;
            }
            push(n3);
        }
        e++;
    }
    printf("Result of evaluation = %d\n", pop());
    return 0;
}