#include <stdio.h>

int main() {
    int pin = 1234;
    int enteredPin;
    int choice;
    float balance = 5000.0, deposit, withdraw;

    printf("Welcome to My ATM!\n");
    printf("Enter your 4-digit PIN: ");
    scanf("%d", &enteredPin);

    if(enteredPin != pin) {
        printf("Incorrect PIN! Access Denied.\n");
        return 0;
    }

    do {
        printf("\n--- ATM Menu ---\n");
        printf("1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Your Balance: %.2f\n", balance);
                break;
            case 2:
                printf("Enter deposit amount: ");
                scanf("%f", &deposit);
                balance += deposit;
                printf("Deposited Successfully! New Balance: %.2f\n", balance);
                break;
            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%f", &withdraw);
                if(withdraw <= balance) {
                    balance -= withdraw;
                    printf("Withdrawal Successful! New Balance: %.2f\n", balance);
                } else {
                    printf("Insufficient Balance!\n");
                }
                break;
            case 4:
                printf("Thank you for using our ATM!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 4);

    return 0;
}