#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#define MAX_ITEMS 100

using namespace std;

struct Item {
    string itemName;
    int quantity;
    float price;
};

using ItemList = vector<Item>;

void printBill(const ItemList& items) {
    float total = 0;
    cout << "\n----------------- Bill  ------------------\n";
    cout << "Item Name\tQuantity\tPrice\tTotal\n";

    for (const auto& item : items) {
        float itemTotal = item.quantity * item.price;
        cout << item.itemName << "\t\t" << item.quantity << "\t\t"
             << fixed << setprecision(2) << item.price << "\t"
             << itemTotal << "\n";
        total += itemTotal;
    }

    cout << "-------------------------------------------------\n";
    cout << "Total Amount: " << fixed << setprecision(2) << total << "\n";
}

int main() {
    ItemList items;
    char choice;

    do {
        if (items.size() >= MAX_ITEMS) {
            cout << "Item limit reached.\n";
            break;
        }

        Item item;
        cout << "Enter item name: ";
        cin >> item.itemName;
        cout << "Enter quantity: ";
        cin >> item.quantity;
        cout << "Enter price: ";
        cin >> item.price;

        items.push_back(item);

        cout << "Do you want to add another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    printBill(items);

    return 0;
}
