#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

const int MAX_PRODUCTS = 100;
const int MAX_STORES = 10;

class Product {
public:
    string name;
    Product(string name = "") : name(name) {}
};

class Store {
public:
    string name, location;
    vector<Product> productList;

    Store(string name, string location) : name(name), location(location) {}

    bool addProduct(string name) {
        if (productList.size() >= MAX_PRODUCTS) {
            cout << "Store full.\n";
            return false;
        }
        productList.push_back(Product(name));
        return true;
    }

    bool searchProduct(string name) {
        for (auto p : productList)
            if (p.name == name) return true;
        return false;
    }

    Product deleteProduct(string name) {
        for (int i = 0; i < productList.size(); ++i) {
            if (productList[i].name == name) {
                Product p = productList[i];
                productList.erase(productList.begin() + i);
                return p;
            }
        }
        return Product("");
    }

    void displayAll() {
        cout << "Products in Store '" << name << "':\n";
        for (auto p : productList)
            cout << "- " << p.name << "\n";
    }
};

class Company {
public:
    string name;
    vector<Store*> arrayStore;

    Company(string name) : name(name) {}

    bool addStore(Store* store) {
        if (arrayStore.size() >= MAX_STORES) {
            cout << "Company full of stores.\n";
            return false;
        }
        arrayStore.push_back(store);
        return true;
    }

    int searchNbofStores(string productName) {
        int count = 0;
        for (auto store : arrayStore)
            if (store->searchProduct(productName)) count++;
        return count;
    }

    void displayAll() {
        cout << "Stores under Company '" << name << "':\n";
        for (auto store : arrayStore)
            cout << "- " << store->name << " (" << store->location << ")\n";
    }
};

// Main function to test
int main() {
    Company* company = new Company("Tech Stores");

    Store* s1 = new Store("Electro_Mart", "Karachi");
    Store* s2 = new Store("Super_Store", "Karachi");
    Store* s3 = new Store("Super_Mart", "Karachi");

    s1->addProduct("Laptop");
    s1->addProduct("Phone");
    s2->addProduct("Phone");
    s2->addProduct("Tablet");
    s2->addProduct("Laptop");
    s3->addProduct("Phone");
    s3->addProduct("Tablet");

    company->addStore(s1);
    company->addStore(s2);
    company->addStore(s3);

    company->displayAll();

    cout << "\nNumber of stores with 'Phone': " 
         << company->searchNbofStores("Phone") << endl;

    cout << "\nProducts in Electro_Mart:\n";
    s1->displayAll();

    Product deleted = s1->deleteProduct("Phone");
    cout << "\nDeleted product: " << deleted.name << endl;

    cout << "\nUpdated list in Electro_Mart:\n";
    s1->displayAll();

    delete s1;
    delete s2;
    delete s3;
    delete company;
    getch();

    return 0;
}