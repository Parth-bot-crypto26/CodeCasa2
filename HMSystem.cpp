#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Customer {
    int roomNumber;
    string name;
    string address;
    double bill;
};

void readCustomerRecords(vector<Customer>& customers) {
    ifstream file("customer_records.txt");
    if (file.is_open()) {
        Customer customer;
        while (file >> customer.roomNumber >> customer.name >> customer.address >> customer.bill) {
            customers.push_back(customer);
        }
        file.close();
    }
}

void writeCustomerRecords(const vector<Customer>& customers) {
    ofstream file("customer_records.txt");
    if (file.is_open()) {
        for (const Customer& customer : customers) {
            file << customer.roomNumber << " " << customer.name << " " << customer.address << " " << customer.bill << "\n";
        }
        file.close();
    }
}

void bookRoom(vector<Customer>& customers) {
    Customer customer;
    cout<<"Enter room number: ";
    cin>>customer.roomNumber;
    cout<<"Enter customer name: ";
    cin.ignore();
    getline(cin, customer.name);
    cout<<"Enter customer address: ";
    getline(cin, customer.address);
    cout<<"Enter bill amount: ";
    cin>>customer.bill;
    customers.push_back(customer);
    writeCustomerRecords(customers);
    cout<<"Room booked successfully."<<endl;
}

void searchCustomerDetails(const vector<Customer>& customers, int roomNumber) {
    for (const Customer& customer : customers) {
        if (customer.roomNumber == roomNumber) {
            cout<<"Room Number: "<<customer.roomNumber<<"\n";
            cout<<"Customer Name: "<<customer.name<<"\n";
            cout<<"Customer Address: "<<customer.address<<"\n";
            cout<<"Bill Amount: "<<customer.bill<<"\n";
            return;
        }
    }
    cout<<"Customer not found for room number: "<<roomNumber<<endl;
}

void displayTotalAllottedRooms(const vector<Customer>& customers) {
    cout<<"Total number of allotted rooms: "<<customers.size()<<endl;
}

void modifyCustomerRecord(vector<Customer>& customers, int roomNumber) {
    for (Customer& customer : customers) {
        if (customer.roomNumber == roomNumber) {
            cout<<"Enter updated customer name: ";
            cin.ignore();
            getline(cin, customer.name);
            cout<<"Enter updated customer address: ";
            getline(cin, customer.address);
            cout<<"Enter updated bill amount: ";
            cin>>customer.bill;
            writeCustomerRecords(customers);
            cout<<"Record updated successfully."<<endl;
            return;
        }
    }
    cout<<"Customer not found for room number: "<<roomNumber<<endl;
}

void deleteCustomerRecord(vector<Customer>& customers, int roomNumber) {
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->roomNumber == roomNumber) {
            customers.erase(it);
            writeCustomerRecords(customers);
            cout<<"Record deleted successfully."<<endl;
            return;
        }
    }
    cout<<"Customer not found for room number: "<<roomNumber<<endl;
}

int main() {
    vector<Customer> customers;
    readCustomerRecords(customers);

    while (true) {
        cout<<"\nHotel Management System\n";
        cout<<"1. Book a room\n";
        cout<<"2. Search customer details\n";
        cout<<"3. Display total allotted rooms\n";
        cout<<"4. Modify customer record\n";
        cout<<"5. Delete customer record\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;

        switch (choice) {
            case 1:
                bookRoom(customers);
                break;
            case 2:
                int roomNumber;
                cout<<"Enter room number to search: ";
                cin>>roomNumber;
                searchCustomerDetails(customers, roomNumber);
                break;
            case 3:
                displayTotalAllottedRooms(customers);
                break;
            case 4:
                int modifyRoomNumber;
                cout<<"Enter room number to modify: ";
                cin>>modifyRoomNumber;
                modifyCustomerRecord(customers, modifyRoomNumber);
                break;
            case 5:
                int deleteRoomNumber;
                cout<<"Enter room number to delete: ";
                cin>>deleteRoomNumber;
                deleteCustomerRecord(customers, deleteRoomNumber);
                break;
            case 6:
                cout<<"Goodbye!"<<endl;
                return 0;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
}
