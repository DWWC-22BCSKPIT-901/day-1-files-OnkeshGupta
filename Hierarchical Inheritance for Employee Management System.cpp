#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
    string name;
    int id;
    double salary;
public:
    Employee(string empName, int empID, double empSalary) : name(empName), id(empID), salary(empSalary) {}

    virtual void calculateEarnings() = 0; 
    virtual void displayDetails() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }

    virtual ~Employee() {} 
};
class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string empName, int empID, double empSalary, double empBonus)
        : Employee(empName, empID, empSalary), bonus(empBonus) {}

    void calculateEarnings() override {
        salary += bonus;
    }

    void displayDetails() override {
        Employee::displayDetails();
        cout << "Bonus: " << bonus << ", Total Earnings: " << salary << endl;
    }
};
class Developer : public Employee {
private:
    int extraHours;
    double hourlyRate;

public:
    Developer(string empName, int empID, double empSalary, int hours, double rate)
        : Employee(empName, empID, empSalary), extraHours(hours), hourlyRate(rate) {}

    void calculateEarnings() override {
        salary += extraHours * hourlyRate;
    }

    void displayDetails() override {
        Employee::displayDetails();
        cout << "Extra Hours: " << extraHours << ", Hourly Rate: " << hourlyRate
             << ", Total Earnings: " << salary << endl;
    }
};
int main() {
    Manager manager("Alice", 101, 50000.0, 10000.0); 
    Developer developer("Bob", 102, 40000.0, 10, 200.0);

    manager.calculateEarnings();
    developer.calculateEarnings();

    cout << "Manager Details:\n";
    manager.displayDetails();

    cout << "\nDeveloper Details:\n";
    developer.displayDetails();

    return 0;
}