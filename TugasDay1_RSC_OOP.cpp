#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Contact{
    private:
    // Informasi-informasi Kontak
    string name;
    string address;
    string element; 
    string weapon;
    string gender;
    public:
        // Constructor Contact untuk inisialisasi
        Contact(string name, string address, string element, string weapon, string gender)   {

            this->name= name;
            this->address = address;
            this->element = element;  // Pyro, Havoc, Imaginary, etc.
            this->weapon = weapon; // Polearm, Sword, Broadblade, etc.
            this->gender =gender; 
        }

        // Getter untuk mendapatkan informasi kontak
        string getName() const{
            return name;
        }

        // Display semua informasi kontak
        void displayInfo() const{
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Element: " << element << endl;
            cout << "Weapon: " << weapon << endl;
            cout << "Gender: " << gender << endl;
        }
};

// Class PhoneBook untuk menyimpan dan mengelola daftar kontak
class PhoneBook{
    private:
        vector<Contact> contacts; // Daftar kontak berupa array yang menyimpan Class Contact
        static int const maximumContacts = 8; // Maksimal konstan 8 kontak
    public:
        // Menambah kontak baru (ADD) ke array contacts
        void addContact(string name, string address, string element, string weapon, string gender){
            if (contacts.size() < maximumContacts){  // Jika jumlah kontak masih kurang dari maximumContacts
                contacts.emplace_back(name, address, element, weapon, gender); // insert kontak di akhir vektor
            }
            else{
                // Jika sudah penuh atau mencapai batas maks, ganti kontak di index pertama, lalu masukan kontak di akhir array
                contacts.erase(contacts.begin());
                contacts.emplace_back(name, address, element, weapon, gender);
            }
            cout << "Contact added successfully!\n";
        }

        // Menampilkan semua nama kontak  (SEARCH)
        void displayAllContacts() const{
            // Jika array kosong.
            if (contacts.empty()){
                cout << "PhoneBook is empty.\n";
                return;
            }
            // Display semua array kontak, lalu getName() disetiap array contacts pada index i.
            cout << "Contact List:\n";
            for (int i = 0; i < contacts.size(); ++i){
                cout << i + 1 << ". " << contacts[i].getName() << endl;
            }
        }

        // Menampilkan Informasi detail kontak berdasarkan Index
        void displayContactDetails(int index) const{
            if (index < 1 || index > contacts.size()){
                cout << "Invalid contact number.\n";
                return;
            }
            contacts[index - 1].displayInfo();
        }
        
        // Menghapus semua kontak (EXIT)
        void clearContacts(){
            contacts.clear();
            cout << "All contacts have been deleted.\n";
        }

        vector<Contact> getContacts(){
            return contacts;
        }

};


int main(){
    PhoneBook phoneBook;
    int choice;

    do{
        cout << "\n=== PhoneBook Menu ===\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contacts\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:{
                //  ADD kontak
                string name, address, element, weapon, gender;

                cout << "Enter name: ";
                cin.ignore(); // Mengatasi masalah newline ketika ada spasi antar kata atau ada nama akhir (etc. Raiden Shogun)
                getline(cin, name);
                
                cout << "Enter address: ";
                getline(cin, address);

                cout << "Enter element (Pyro, Havoc, Imaginary, etc.): ";
                getline(cin, element);

                cout << "Enter weapon (Polearm, Sword, Broadblade, etc): ";
                getline(cin, weapon);

                cout << "Enter gender (Male/Female): ";
                getline(cin, gender);

                phoneBook.addContact(name, address, element, weapon, gender);
                break;
            }

            case 2:{
                // SEARCH kontak
                phoneBook.displayAllContacts();

                // Jika PhoneBook kosong, berhentikan loop.
                if (phoneBook.getContacts().size() == 0){
                    break;
                }

                cout << "Enter the contact number to view details: ";    
                int index;
                cin >> index;
                cout << '\n';

                phoneBook.displayContactDetails(index);
                  break;
            }

            case 3:{
                phoneBook.clearContacts();
                cout << "Exiting program...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);
    return 0;
}