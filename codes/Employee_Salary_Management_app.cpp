

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <stdexcept>

using namespace std;

// Base class Employee
class Employee {
protected:
    string firstName;
    string lastName;
    string CNIC;

public:
    // Default constructor
    Employee() : firstName(""), lastName(""), CNIC("") {}

    // Parameterized constructor
    Employee(string first, string last, string cnic)
        : firstName(first), lastName(last), CNIC(cnic) {}

    // Getters and setters
    string getFirstName() const { return firstName; }
    void setFirstName(string name) { firstName = name; }

    string getLastName() const { return lastName; }
    void setLastName(string name) { lastName = name; }

    string getCNIC() const { return CNIC; }
    void setCNIC(string cnic) { CNIC = cnic; }

    // Virtual method to be overridden
    virtual double earnings() const = 0;

    // Virtual toString equivalent
    virtual string toString() const {
        return firstName + " " + lastName + " CNIC# " + CNIC;
    }

    // Pure virtual function makes this an abstract class
    virtual ~Employee() {}
};

// SalariedEmployee derived from Employee
class SalariedEmployee : public Employee {
private:
    double weeklySalary;

public:
    SalariedEmployee() : Employee(), weeklySalary(0.0) {}

    SalariedEmployee(string first, string last, string cnic, double salary)
        : Employee(first, last, cnic), weeklySalary(0.0) {
        setWeeklySalary(salary);
    }

    double getWeeklySalary() const { return weeklySalary; }
    void setWeeklySalary(double salary) {
        if (salary < 0)
            throw invalid_argument("Weekly salary cannot be negative.");
        weeklySalary = salary;
    }

    double earnings() const override {
        return weeklySalary;
    }

    string toString() const override {
        return "\nSalaried employee: " + Employee::toString();
    }
};

// HourlyEmployee derived from Employee
class HourlyEmployee : public Employee {
private:
    double wage;
    double hours;

public:
    HourlyEmployee() : Employee(), wage(0.0), hours(0.0) {}

    HourlyEmployee(string first, string last, string cnic, double hourlyWage, double workHours)
        : Employee(first, last, cnic), wage(0.0), hours(0.0) {
        setWage(hourlyWage);
        setHours(workHours);
    }

    double getWage() const { return wage; }
    void setWage(double hourlyWage) {
        if (hourlyWage < 0)
            throw invalid_argument("Hourly wage cannot be negative.");
        wage = hourlyWage;
    }

    double getHours() const { return hours; }
    void setHours(double workHours) {
        if (workHours < 0)
            throw invalid_argument("Work hours cannot be negative.");
        hours = workHours;
    }

    double earnings() const override {
        if (hours <= 40)
            return wage * hours;
        else
            return (40 * wage) + ((hours - 40) * wage * 1.5);
    }

    string toString() const override {
        return "\nHourly employee: " + Employee::toString();
    }
};

// CommissionEmployee derived from Employee
class CommissionEmployee : public Employee {
private:
    double grossSales;
    double commissionRate;

public:
    CommissionEmployee() : Employee(), grossSales(0.0), commissionRate(0.0) {}

    CommissionEmployee(string first, string last, string cnic, double sales, double rate)
        : Employee(first, last, cnic), grossSales(0.0), commissionRate(0.0) {
        setGrossSales(sales);
        setCommissionRate(rate);
    }

    double getGrossSales() const { return grossSales; }
    void setGrossSales(double sales) {
        if (sales < 0)
            throw invalid_argument("Gross sales cannot be negative.");
        grossSales = sales;
    }

    double getCommissionRate() const { return commissionRate; }
    void setCommissionRate(double rate) {
        if (rate < 0 || rate > 1)
            throw invalid_argument("Commission rate must be between 0 and 1.");
        commissionRate = rate;
    }

    double earnings() const override {
        return grossSales * commissionRate;
    }

    string toString() const override {
        return "\nCommission employee: " + Employee::toString();
    }
};

// BasePlusCommissionEmployee derived from CommissionEmployee
class BasePlusCommissionEmployee : public CommissionEmployee {
private:
    double baseSalary;

public:
    BasePlusCommissionEmployee() : CommissionEmployee(), baseSalary(0.0) {}

    BasePlusCommissionEmployee(string first, string last, string cnic,
                                double sales, double rate, double salary)
        : CommissionEmployee(first, last, cnic, sales, rate), baseSalary(0.0) {
        setBaseSalary(salary);
    }

    double getBaseSalary() const { return baseSalary; }
    void setBaseSalary(double salary) {
        if (salary < 0)
            throw invalid_argument("Base salary cannot be negative.");
        baseSalary = salary;
    }

    double earnings() const override {
        return baseSalary + CommissionEmployee::earnings();
    }

    string toString() const override {
        return "\nBase plus Commission employee: " + CommissionEmployee::toString();
    }
};

// Helper function to get valid numeric input
template <typename T>
T getValidInput(const string& prompt) {
    T value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear(); // clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input. Please enter a valid number: ";
    }
    return value;
}

int main() {
    cout << fixed << setprecision(2);

    vector<Employee*> employees;

    int choice;
    do {
        cout << "\n=== Add Employee ===\n";
        cout << "1. Salaried Employee\n";
        cout << "2. Hourly Employee\n";
        cout << "3. Commission Employee\n";
        cout << "4. Base Plus Commission Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            string first, last, cnic;

            cout << "Enter First Name: ";
            cin >> first;
            cout << "Enter Last Name: ";
            cin >> last;
            cout << "Enter CNIC: ";
            cin >> cnic;

            try {
                switch (choice) {
                    case 1: {
                        double salary = getValidInput<double>("Enter Weekly Salary: ");
                        employees.push_back(new SalariedEmployee(first, last, cnic, salary));
                        break;
                    }
                    case 2: {
                        double wage = getValidInput<double>("Enter Hourly Wage: ");
                        double hours = getValidInput<double>("Enter Hours Worked: ");
                        employees.push_back(new HourlyEmployee(first, last, cnic, wage, hours));
                        break;
                    }
                    case 3: {
                        double sales = getValidInput<double>("Enter Gross Sales: ");
                        double rate = getValidInput<double>("Enter Commission Rate (e.g., 0.06): ");
                        employees.push_back(new CommissionEmployee(first, last, cnic, sales, rate));
                        break;
                    }
                    case 4: {
                        double sales = getValidInput<double>("Enter Gross Sales: ");
                        double rate = getValidInput<double>("Enter Commission Rate (e.g., 0.06): ");
                        double base = getValidInput<double>("Enter Base Salary: ");
                        employees.push_back(new BasePlusCommissionEmployee(first, last, cnic, sales, rate, base));
                        break;
                    }
                }
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
    } while (choice != 5);

    // Display all employees
    cout << "\n=== Employee Payroll Summary ===\n";
    for (const auto& emp : employees) {
        cout << emp->toString() << endl;
        cout << "Earnings: $" << emp->earnings() << endl << endl;
    }

    // Free memory
    for (auto& emp : employees) {
        delete emp;
    }

    return 0;
}