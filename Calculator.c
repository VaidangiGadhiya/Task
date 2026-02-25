#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main() {
    int choice, num1, num2;
    char cont = 'y';

    printf("===== Simple Calculator =====\n");

    while(cont == 'y' || cont == 'Y') {
        printf("\nSelect Operation:\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 5) {
            printf("Exiting Calculator. Goodbye!\n");
            break;
        }

        if(choice >=1 && choice <=4) {
            printf("Enter first number: ");
            scanf("%d", &num1);
            printf("Enter second number: ");
            scanf("%d", &num2);
        }

        switch(choice) {
            case 1: printf("Result: %d\n", add(num1, num2)); break;
            case 2: printf("Result: %d\n", subtract(num1, num2)); break;
            case 3: printf("Result: %d\n", multiply(num1, num2)); break;
            case 4:
                if(num2 != 0)
                    printf("Result: %.2f\n", divide(num1, num2));
                else
                    printf("Error: Division by zero!\n");
                break;
            default: printf("Invalid choice! Please select 1-5.\n");
        }

        if(choice != 5) {
            printf("\nDo you want to perform another operation? (y/n): ");
            scanf(" %c", &cont);
        }
    }

    return 0;
}


int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
float divide(int a, int b) { return (float)a / b; }