#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() = 0;
    Employee* next = nullptr;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    double salary;
public:
    FullTimeEmployee(double s) : salary(s) {}
    double calculateSalary() override { return salary; }
};

class PartTimeEmployee : public Employee {
    double rate; int hours;
public:
    PartTimeEmployee(double r, int h) : rate(r), hours(h) {}
    double calculateSalary() override { return rate * hours; }
};

int main() {
    Employee* head = new FullTimeEmployee(60000);
    head->next = new PartTimeEmployee(500, 40);
    Employee* temp = head;
    int count = 1;
    while (temp != nullptr) {
        cout << "Employee " << count << " Salary: " << temp->calculateSalary() << endl;
        temp = temp->next;
        count++;
    }
    delete head->next;
    delete head;

    return 0;
}