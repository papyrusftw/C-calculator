#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int IsInteger(const char *str) {
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
    double result;
    
    printf("Enter an operator (+;-;*;/): ");
    scanf(" %c", &operator);
    printf("Enter the first number (integer only): ");
    scanf("%s", input1);
    if (!IsInteger(input1)) {
        printf("The first number isn't an integer.\n");
        return 1;
    }
    
    printf("Enter the second number (integer only): ");
    scanf("%s", input2);
    if (!IsInteger(input2)) {
        printf("The second number isn't an integer.\n");
        return 1;
    }
    
    num1 = atoi(input1);
    num2 = atoi(input2);
    
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case '/':
            if (num2 != 0) {
                // Cast to double for decimal division
                result = (double)num1 / num2;
                printf("Result: %.2f\n", result);
            } else {
                printf("Division by zero isn't possible.\n");
            }
            break;
        default:
            printf("Invalid operator.\n");
    }
    return 0;
}
