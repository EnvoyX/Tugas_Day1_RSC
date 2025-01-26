#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class untuk menyimpan informasi kontak
class Contact {
private:
    string name;
    string address;
    string element; // Elemen seperti Pyro, Cryo, dll.

public:
    // Constructor Contact untuk inisialisasi
    Contact(string name, string address, string element) {
        this->name = name;
        this->address = address;
        this->element = element;
    }

    // Getter untuk mendapatkan informasi kontak
    string getName() const {
        return name;
    }

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Element: " << element << endl;
    }
};

// Class PhoneBook untuk menyimpan dan mengelola daftar kontak
class PhoneBook {
private:
    vector<Contact> contacts; // Daftar kontak
    static const int  maximumContacts = 8; // Maksimal 8 kontak

public:
    // Menambahkan kontak baru (ADD)
    void addContact(string name, string address, string element) {
        if (contacts.size() <  maximumContacts) {
            contacts.emplace_back(name, address, element); // insert kontak di akhir vektor
        } else {
            // Jika sudah penuh, ganti kontak pertama
            contacts.erase(contacts.begin()); 
            contacts.emplace_back(name, address, element);
        }
        cout << "Contact added successfully!\n";
    }

    // Menampilkan semua nama kontak  (SEARCH)
    void displayAllContacts() const {
        if (contacts.empty()) {
            cout << "PhoneBook is empty.\n";
            return;
        }

        cout << "Contact List:\n";
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << i + 1 << ". " << contacts[i].getName() << endl;
        }
    }

    // Menampilkan informasi detail kontak berdasarkan indeks (SEARCH)
    void displayContactDetails(int index) const {
        if (index < 1 || index > contacts.size()) {
            cout << "Invalid contact number.\n";
            return;
        }
        contacts[index - 1].displayInfo();
    }

    // Menghapus semua kontak (EXIT)
    void clearContacts() {
        contacts.clear();
        cout << "All contacts have been deleted.\n";
    }
};

// Fungsi utama
int main() {
    PhoneBook phoneBook;
    int choice;

    do {
        cout << "\n=== PhoneBook Menu ===\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contacts\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Tambahkan kontak
            string name, address, element;
            cout << "Enter name: ";
            cin.ignore(); // Mengatasi masalah newline
            getline(cin, name);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter element (Pyro, Cryo, etc.): ";
            getline(cin, element);

            phoneBook.addContact(name, address, element);
            break;
        }
        case 2: {
            // Cari kontak
            phoneBook.displayAllContacts();
            cout << "Enter the contact number to view details: ";
            int index;
            cin >> index;
            phoneBook.displayContactDetails(index);
            break;
        }
        case 3:
            // Keluar dan hapus semua data
            phoneBook.clearContacts();
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}