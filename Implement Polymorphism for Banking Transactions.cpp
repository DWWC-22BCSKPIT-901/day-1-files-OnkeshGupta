#include <iostream>
using namespace std;
class Account {
protected:
    double balance;

public:
    Account(double bal) : balance(bal) {}

    virtual void calculateInterest() = 0; 

    virtual void displayBalance() {
        cout << "Current Balance: " << balance << endl;
    }

    virtual ~Account() {} 
};
class SavingsAccount : public Account {
private:
    double rate;
    double time;

public:
    SavingsAccount(double bal, double r, double t) : Account(bal), rate(r), time(t) {}

    void calculateInterest() override {
        double interest = balance * rate * time;
        balance += interest;
        cout << "Savings Account: Interest added: " << interest << endl;
    }
};
class CurrentAccount : public Account {
private:
    double maintenanceFee;

public:
    CurrentAccount(double bal, double fee) : Account(bal), maintenanceFee(fee) {}

    void calculateInterest() override {
        balance -= maintenanceFee;
        cout << "Current Account: Maintenance fee deducted: " << maintenanceFee << endl;
    }
};
int main() {
    Account* accounts[2];

    accounts[0] = new SavingsAccount(1000.0, 0.05, 1.0); 
    accounts[1] = new CurrentAccount(2000.0, 50.0);       
    for (int i = 0; i < 2; ++i) {
        accounts[i]->calculateInterest();
        accounts[i]->displayBalance();
        delete accounts[i];
    }

    return 0;
}