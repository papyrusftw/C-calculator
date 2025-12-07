#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isInteger(const char *str) {
    if (*str == '-') str++;
    if (*str == '\0') return 0;
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}
int main() {
    char operator;
    char input1[50], input2[50];
    int num1, num2;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter first integer: ");
    scanf("%s", input1);
    if (!isInteger(input1)) {
        printf("Error: First input is not an integer.\n");
        return 1;
    }
    printf("Enter second integer: ");
    scanf("%s", input2);
    if (!isInteger(input2)) {
        printf("Error: Second input is not an integer.\n");
        return 1;
    }
    
    num1 = atoi(input1);
    num2 = atoi(input2);
    
    switch (operator) {
        case '+':
            printf("Result: %d\n", num1 + num2);
            break;
        case '-':
            printf("Result: %d\n", num1 - num2);
            break;
        case '*':
            printf("Result: %d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Result: %d\n", num1 / num2);
            else
                printf("Error: Division by zero isnt possible.\n");
            break;
        default:
            printf("Invalid operator.\n");
    }
    return 0;
}
