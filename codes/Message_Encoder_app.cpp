#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class Message
{
    protected:
        string text;

    public:
        Message() : text("") {}
        explicit Message(const string& txt) : text(txt) {}

        void setText(const string& txt) { text = txt; }
        string getText() const { return text; }

        virtual string toString() const
        {
            return text;
        }

        virtual ~Message() = default;
};

class SMS : public Message
{
    private:
        string recipientContactNo;

    public:
        SMS(const string& txt, const string& contact)
            : Message(txt), recipientContactNo(contact) {}

        void setRecipient(const string& contact)
        {
            recipientContactNo = contact;
        }

        string getRecipient() const
        {
            return recipientContactNo;
        }

        string toString() const override
        {
            return "SMS to " + recipientContactNo + ": " + Message::toString();
        }
};

// Email class derived from Message
class Email : public Message {
private:
    string sender;
    string receiver;
    string subject;

public:
    Email(const string& txt, const string& snd, const string& rcv, const string& sub)
        : Message(txt), sender(snd), receiver(rcv), subject(sub) {}

    void setSender(const string& snd) { sender = snd; }
    void setReceiver(const string& rcv) { receiver = rcv; }
    void setSubject(const string& sub) { subject = sub; }

    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    string getSubject() const { return subject; }

    string toString() const override {
        return "From: " + sender + "\nTo: " + receiver +
               "\nSubject: " + subject + "\nBody: " + Message::toString();
    }
};

// Function to check if a keyword is present in the message
bool containsKeyword(const Message& messageObject, const string& keyword) {
    size_t found = messageObject.toString().find(keyword);
    return found != string::npos;
}

// Encoding function: shifts each letter by one (circular for z/Z -> a/A)
string encodeMessage(const string& input) {
    string encoded = input;
    for (char &ch : encoded) {
        if ((ch >= 'a' && ch < 'z') || (ch >= 'A' && ch < 'Z')) {
            ch++;
        } else if (ch == 'z') {
            ch = 'a';
        } else if (ch == 'Z') {
            ch = 'A';
        }
        // Non-alphabetic characters remain unchanged
    }
    return encoded;
}

// Main function to test the classes with user input
int main() {
    vector<SMS> smsList;
    vector<Email> emailList;

    int choice;
    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Add SMS\n";
        cout << "2. Add Email\n";
        cout << "3. Display All Messages\n";
        cout << "4. Check Keyword in Messages\n";
        cout << "5. Encode a Custom Message\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle newline after integer input

        switch (choice) {
            case 1: {
                string text, contact;
                cout << "Enter SMS text: ";
                getline(cin, text);
                cout << "Enter recipient contact number: ";
                getline(cin, contact);

                smsList.emplace_back(text, contact);
                cout << "SMS added successfully.\n";
                break;
            }

            case 2: {
                string text, sender, receiver, subject;
                cout << "Enter email body: ";
                getline(cin, text);
                cout << "Enter sender: ";
                getline(cin, sender);
                cout << "Enter receiver: ";
                getline(cin, receiver);
                cout << "Enter subject: ";
                getline(cin, subject);

                emailList.emplace_back(text, sender, receiver, subject);
                cout << "Email added successfully.\n";
                break;
            }

            case 3: {
                cout << "\n=== SMS Messages ===\n";
                for (size_t i = 0; i < smsList.size(); ++i) {
                    cout << "SMS " << i + 1 << ":\n" << smsList[i].toString() << "\n----------------------\n";
                }

                cout << "\n=== Email Messages ===\n";
                for (size_t i = 0; i < emailList.size(); ++i) {
                    cout << "Email " << i + 1 << ":\n" << emailList[i].toString() << "\n----------------------\n";
                }
                break;
            }

            case 4: {
                string keyword;
                cout << "Enter keyword to search: ";
                getline(cin, keyword);

                bool found = false;

                for (const auto& sms : smsList) {
                    if (containsKeyword(sms, keyword)) {
                        cout << "Keyword found in an SMS.\n";
                        found = true;
                    }
                }

                for (const auto& email : emailList) {
                    if (containsKeyword(email, keyword)) {
                        cout << "Keyword found in an Email.\n";
                        found = true;
                    }
                }

                if (!found) {
                    cout << "Keyword not found in any message.\n";
                }
                break;
            }

            case 5: {
                string userInput;
                cout << "Enter message to encode: ";
                getline(cin, userInput);

                string encoded = encodeMessage(userInput);
                cout << "Encoded message: " << encoded << endl;
                break;
            }

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    getch();

    return 0;
}