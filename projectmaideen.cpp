#include <iostream>
using namespace std;

class Account {
protected:
    int accNumber;
    string accHolder;
    double balance;

public:
    Account(int num, string name, double bal) {
        accNumber = num;
        accHolder = name;
        balance = bal;
    }
    void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn Successfully!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void display() {
        cout << "\nAccount Details:\n";
        cout << "Account Number: " << accNumber << endl;
        cout << "Account Holder: " << accHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int num, string name, double bal)
        : Account(num, name, bal) {}
};

int main() {
    int number;
    string name;
    double balance, amount;
    int choice;

    cout << "Enter Account Number: ";
    cin >> number;
    cout << "Enter Account Holder Name: ";
    cin >> name;
    cout << "Enter Initial Balance: ";
    cin >> balance;

    SavingsAccount acc(number, name, balance);

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc.deposit(amount);
            break;

        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
            break;

        case 3:
            acc.display();
            break;

        case 4:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
