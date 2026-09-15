#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string owner;
    double balance;

public:
    Account(string ownerName, double initialBalance = 0.0) {
        owner = ownerName;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " EGP. New balance: " << balance << " EGP\n";
        } else {
            cout << "Error: Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Error: Insufficient funds. Current balance: " << balance << " EGP\n";
        } else if (amount <= 0) {
            cout << "Error: Invalid withdrawal amount.\n";
        } else {
            balance -= amount;
            cout << "Withdrew " << amount << " EGP. New balance: " << balance << " EGP\n";
        }
    }

    void checkBalance() const {
        cout << "Current balance: " << balance << " EGP\n";
    }
};

int main() {
    Account acc("User", 0);
    int choice = 0;

    while (choice != 4) {
        cout << "\n=== Bank System ===\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc.deposit(amount);
        } else if (choice == 2) {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
        } else if (choice == 3) {
            acc.checkBalance();
        } else if (choice == 4) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}