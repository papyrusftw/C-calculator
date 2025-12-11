#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int IsFloat(const char *str) {
    int HasDecimal = 0;
    if (*str == '-') str++;
    if (*str == '\0') return 0;
    while (*str) {
        if (*str == '.'){
            if (HasDecimal) return 0;
            HasDecimal = 1;
        }
         else if (!isdigit(*str)){
            return 0;
         }
        str++;
    }
    return 1;
}

int main() {
    char operator;
    char input1[50], input2[50];
    double num1, num2;
    double result;
    printf("Enter an operator (+;-;*;/): ");
    scanf(" %c", &operator);
    printf("Enter the first number: ");
    scanf("%s", input1);
    if (!IsFloat(input1)) {
        printf("The first number isnt a valid number.\n");
        return 1;
    }
    
    printf("Enter the second number: ");
    scanf("%s", input2);
    if (!IsFloat(input2)) {
        printf("The second number isnt a valid number.\n");
        return 1;
    }
    
    num1 = atof(input1);
    num2 = atof(input2);
    
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
