#include <iostream>
#include<string>
#include <vector>
using namespace std;

class Customer {
private:
    string name;
    int accountNumber;
    double balance;

public:
    static int totalCustomers;
    static double totalBankBalance;

    Customer(string n, int accNo, double bal) {
        name = n;
        accountNumber = accNo;
        balance = bal;
        totalCustomers++;
        totalBankBalance += bal;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            totalBankBalance += amount;
            cout << " Deposit Successful!\n";
        } else {
            cout << " Invalid Amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << " Invalid Amount!\n";
        } else if (amount > balance) {
            cout << " Insufficient Balance!\n";
        } else {
            balance -= amount;
            totalBankBalance -= amount;
            cout << " Withdrawal Successful!\n";
        }
    }

    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Name: " << name << endl;
        cout << "Account No: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int Customer::totalCustomers = 0;
double Customer::totalBankBalance = 0;

int main() {
    vector<Customer> customers;
    int choice;

    while (true) {
        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account\n";
        cout << "5. Bank Summary\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int accNo;
            double balance;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Initial Balance: ";
            cin >> balance;

            customers.push_back(Customer(name, accNo, balance));
            cout << " Account Created Successfully!\n";
        }

        else if (choice == 2) {
            int accNo;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (auto &c : customers) {
                if (c.getAccountNumber() == accNo) {
                    cout << "Enter Amount: ";
                    cin >> amount;
                    c.deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << " Account Not Found!\n";
        }

        else if (choice == 3) {
            int accNo;
            double amount;
            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (auto &c : customers) {
                if (c.getAccountNumber() == accNo) {
                    cout << "Enter Amount: ";
                    cin >> amount;
                    c.withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) cout << " Account Not Found!\n";
        }

        else if (choice == 4) {
            int accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;
            for (auto &c : customers) {
                if (c.getAccountNumber() == accNo) {
                    c.display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << " Account Not Found!\n";
        }

        else if (choice == 5) {
            cout << "\n--- Bank Summary ---\n";
            cout << "Total Customers: " << Customer::totalCustomers << endl;
            cout << "Total Bank Balance: " << Customer::totalBankBalance << endl;
        }

        else if (choice == 6) {
            cout << " Exiting...\n";
            break;
        }

        else {
            cout << " Invalid Choice!\n";
        }
    }

    return 0;
}