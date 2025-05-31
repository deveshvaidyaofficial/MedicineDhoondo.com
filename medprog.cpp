#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Medicine {
public:
    int id;
    string name;
    string type;
    int quantity;

    Medicine(int medicineId, string medicineName, string medicineType, int stock) {
        id = medicineId;
        name = medicineName;
        type = medicineType;
        quantity = stock;
    }

    void show() {
        cout << "ID: " << id << " | Name: " << name 
             << " | Type: " << type << " | Quantity: " << quantity << endl;
    }
};

class MedicineStore {
private:
    vector<Medicine> medicines;

public:
    void addMedicine() {
        cout << "\n--- Add New Medicine ---" << endl;
        int id, quantity;
        string name, type;
        
        cout << "Enter Medicine ID: ";
        cin >> id;
        
        for (int i = 0; i < medicines.size(); i++) {
            if (medicines[i].id == id) {
                cout << "Medicine with this ID already exists!" << endl;
                return;
            }
        }
        
        cin.ignore();
        cout << "Enter Medicine Name: ";
        getline(cin, name);
        cout << "Enter Medicine Type (Tablet/Syrup/Capsule): ";
        getline(cin, type);
        cout << "Enter Quantity: ";
        cin >> quantity;
        
        Medicine newMedicine(id, name, type, quantity);
        medicines.push_back(newMedicine);
        cout << "Medicine added successfully!" << endl;
    }
    
    void searchMedicine() {
        if (medicines.empty()) {
            cout << "No medicines available in store." << endl;
            return;
        }
        
        cout << "\n--- Search Medicine ---" << endl;
        string searchName;
        cin.ignore();
        cout << "Enter medicine name to search: ";
        getline(cin, searchName);
        
        bool found = false;
        for (int i = 0; i < medicines.size(); i++) {
            if (medicines[i].name == searchName) {
                cout << "Medicine found:" << endl;
                medicines[i].show();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Medicine not found!" << endl;
        }
    }
    
    void showAllMedicines() {
        if (medicines.empty()) {
            cout << "No medicines available in store." << endl;
            return;
        }
        
        cout << "\n--- All Medicines ---" << endl;
        for (int i = 0; i < medicines.size(); i++) {
            medicines[i].show();
        }
        cout << "Total medicines: " << medicines.size() << endl;
    }
    
    void removeMedicine() {
        if (medicines.empty()) {
            cout << "No medicines to remove." << endl;
            return;
        }
        
        cout << "\n--- Remove Medicine ---" << endl;
        int removeId;
        cout << "Enter medicine ID to remove: ";
        cin >> removeId;
        
        for (int i = 0; i < medicines.size(); i++) {
            if (medicines[i].id == removeId) {
                cout << "Removing: ";
                medicines[i].show();
                
                char confirm;
                cout << "Are you sure? (y/n): ";
                cin >> confirm;
                
                if (confirm == 'y' || confirm == 'Y') {
                    medicines.erase(medicines.begin() + i);
                    cout << "Medicine removed successfully!" << endl;
                } else {
                    cout << "Remove cancelled." << endl;
                }
                return;
            }
        }
        
        cout << "Medicine with ID " << removeId << " not found!" << endl;
    }
    
    void showMenu() {
        cout << "\n====== MEDICINE STORE ======" << endl;
        cout << "1. Add Medicine" << endl;
        cout << "2. Search Medicine" << endl;
        cout << "3. Show All Medicines" << endl;
        cout << "4. Remove Medicine" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
    }
    
    void start() {
        cout << "Welcome to Medicine Store Management System!" << endl;
        
        int choice;
        while (true) {
            showMenu();
            cin >> choice;
            
            if (choice == 1) {
                addMedicine();
            }
            else if (choice == 2) {
                searchMedicine();
            }
            else if (choice == 3) {
                showAllMedicines();
            }
            else if (choice == 4) {
                removeMedicine();
            }
            else if (choice == 5) {
                cout << "Thank you for using Medicine Store System!" << endl;
                break;
            }
            else {
                cout << "Please enter a number between 1 and 5!" << endl;
            }
        }
    }
};

int main() {
    MedicineStore store;
    store.start();
    return 0;
}