

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Birthday class (composed in Person)
class Birthday {
private:
    string month;
    int day;
    int year;

public:
    // Constructor
    Birthday(int d = 1, string m = "Jan", int y = 2000) : day(d), month(m), year(y) {}

    // Setters
    void setDay(int d) { day = d; }
    void setMonth(string m) { month = m; }
    void setYear(int y) { year = y; }

    // Getters
    int getDay() const { return day; }
    string getMonth() const { return month; }
    int getYear() const { return year; }

    // Display birthday
    void display() const {
        cout << day << " " << month << " " << year;
    }
};

// Address class (composed in Person)
class Address {
private:
    int zipCode;
    string city;
    string province;
    string country;

public:
    Address(int zip = 0, string c = "Unknown", string p = "Unknown", string co = "Unknown")
        : zipCode(zip), city(c), province(p), country(co) {}

    // Setters
    void setZipCode(int zip) { zipCode = zip; }
    void setCity(string c) { city = c; }
    void setProvince(string p) { province = p; }
    void setCountry(string co) { country = co; }

    // Display address
    void display() const {
        cout << "ZIP Code: " << zipCode << ", City: " << city
             << ", Province: " << province << ", Country: " << country;
    }
};

// Person class (composes Birthday and Address)
class Person {
private:
    string name;
    Birthday dob;
    Address adr;

public:
    Person(string n = "Unknown", Birthday b = Birthday(), Address a = Address())
        : name(n), dob(b), adr(a) {}

    // Setters
    void setName(string n) { name = n; }

    void setBirthday(int d, string m, int y) {
        dob.setDay(d);
        dob.setMonth(m);
        dob.setYear(y);
    }

    void setAddress(int zip, string city, string province, string country) {
        adr.setZipCode(zip);
        adr.setCity(city);
        adr.setProvince(province);
        adr.setCountry(country);
    }

    // Display person info
    void display() const {
        cout << "\nName: " << name << endl;
        cout << "Date of Birth: ";
        dob.display();
        cout << "\nAddress: ";
        adr.display();
        cout << "\n-----------------------------\n";
    }
};

// Utility function to clear input buffer
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<Person> people;
    int choice;

    do {
        cout << "\n=== Person Management System ===\n";
        cout << "1. Add New Person\n";
        cout << "2. View All People\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, month, city, province, country;
                int day, year, zip;

                cout << "Enter Name: ";
                clearInputBuffer(); // Clear any leftover newline
                getline(cin, name);

                cout << "Enter Date of Birth:\n";
                cout << "Day: ";
                cin >> day;
                cout << "Month: ";
                clearInputBuffer();
                getline(cin, month);
                cout << "Year: ";
                cin >> year;

                cout << "Enter Address:\n";
                cout << "ZIP Code: ";
                cin >> zip;
                cout << "City: ";
                clearInputBuffer();
                getline(cin, city);
                cout << "Province: ";
                getline(cin, province);
                cout << "Country: ";
                getline(cin, country);

                Person newPerson(name, Birthday(day, month, year), Address(zip, city, province, country));
                people.push_back(newPerson);

                cout << "\nPerson added successfully!\n";
                break;
            }

            case 2:
                if (people.empty()) {
                    cout << "\nNo records found.\n";
                } else {
                    cout << "\n=== All People ===\n";
                    for (const auto& p : people) {
                        p.display();
                    }
                }
                break;

            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}