#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

// Base class Person
class Person {
protected:
    string firstName;
    string lastName;

public:
    // Default constructor
    Person() : firstName(""), lastName("") {}

    // Parameterized constructor
    Person(string first, string last) : firstName(first), lastName(last) {}

    // Accessors
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }

    // Mutators
    void setFirstName(string name) { firstName = name; }
    void setLastName(string name) { lastName = name; }

    // Display method
    virtual void displayDetails() const {
        cout << "Name: " << firstName << " " << lastName << endl;
    }

    virtual ~Person() {} // Virtual destructor
};

// Derived class Student
class Student : public Person {
private:
    int studentID;
    string course;
    string teacherName;

public:
    // Constructor
    Student(string first, string last, int id, string courseName, string teacher)
        : Person(first, last), studentID(id), course(courseName), teacherName(teacher) {}

    // Override displayDetails
    void displayDetails() const override {
        Person::displayDetails(); // Call base class method
        cout << "Student ID: " << studentID << endl;
        cout << "Course: " << course << endl;
        cout << "Teacher: " << teacherName << endl;
    }
};

// Derived class Teacher
class Teacher : public Person {
private:
    string subject;
    double salary;

public:
    // Constructor
    Teacher(string first, string last, string subjectName, double salaryAmount)
        : Person(first, last), subject(subjectName), salary(salaryAmount) {}

    // Override displayDetails
    void displayDetails() const override {
        Person::displayDetails(); // Call base class method
        cout << "Subject: " << subject << endl;
        cout << "Salary: $" << salary << endl;
    }
};

// Main function to test the classes with user input
int main() {
    vector<Student> students;
    vector<Teacher> teachers;

    int choice;
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Display All Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore newline after number input

        switch (choice) {
            case 1: {
                string first, last, course, teacher;
                int id;

                cout << "Enter first name: ";
                getline(cin, first);
                cout << "Enter last name: ";
                getline(cin, last);
                cout << "Enter student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter course: ";
                getline(cin, course);
                cout << "Enter teacher name: ";
                getline(cin, teacher);

                students.emplace_back(first, last, id, course, teacher);
                cout << "Student added.\n";
                break;
            }

            case 2: {
                string first, last, subject;
                double salary;

                cout << "Enter first name: ";
                getline(cin, first);
                cout << "Enter last name: ";
                getline(cin, last);
                cout << "Enter subject: ";
                getline(cin, subject);
                cout << "Enter salary: ";
                cin >> salary;
                cin.ignore();

                teachers.emplace_back(first, last, subject, salary);
                cout << "Teacher added.\n";
                break;
            }

            case 3: {
                cout << "\n=== Student Details ===\n";
                for (const auto& s : students) {
                    s.displayDetails();
                    cout << "----------------------\n";
                }

                cout << "\n=== Teacher Details ===\n";
                for (const auto& t : teachers) {
                    t.displayDetails();
                    cout << "----------------------\n";
                }
                break;
            }

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    getch();

    return 0;
}