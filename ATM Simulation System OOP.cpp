#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    int pin;
    double balance;

public:
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cout << "Set 4-digit PIN: ";
        cin >> pin;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        cout << "Account Created Successfully!\n";
    }

    int getAccountNumber() {
        return accountNumber;
    }

    bool verifyPin() {
        int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin)
            return true;
        else {
            cout << "Incorrect PIN!\n";
            return false;
        }
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit Successful!\n";
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount accounts[100];
    int totalAccounts = 0;
    int choice, accNo;

    cout << "===== Advanced ATM System =====\n";

    while (true) {
        cout << "\n1. Create Account";
        cout << "\n2. Access Account";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            accounts[totalAccounts].createAccount();
            totalAccounts++;
        }
        else if (choice == 2) {
            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;

            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accNo) {
                    found = true;

                    if (accounts[i].verifyPin()) {
                        int option;

                        do {
                            cout << "\n--- ATM Menu ---";
                            cout << "\n1. Deposit";
                            cout << "\n2. Withdraw";
                            cout << "\n3. Balance Inquiry";
                            cout << "\n4. Back";
                            cout << "\nEnter option: ";
                            cin >> option;

                            switch (option) {
                                case 1:
                                    accounts[i].deposit();
                                    break;
                                case 2:
                                    accounts[i].withdraw();
                                    break;
                                case 3:
                                    accounts[i].checkBalance();
                                    break;
                                case 4:
                                    cout << "Returning to Main Menu...\n";
                                    break;
                                default:
                                    cout << "Invalid Option!\n";
                            }
                        } while (option != 4);
                    }
                }
            }

            if (!found)
                cout << "Account Not Found!\n";
        }
        else if (choice == 3) {
            cout << "Thank you for using ATM!\n";
            break;
        }
        else {
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}