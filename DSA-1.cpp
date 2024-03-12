#include<iostream>
using namespace std;

struct TF {
    int value;
    TF* link;
};

class Telephone {
private:
    TF* HT[10];

public:
    Telephone() {
        for (int i = 0; i < 10; i++) {
            HT[i] = NULL;
        }
    }

    int Fn_hash(int value) {
        return (value % 10);
    }

    void print() {
        for (int i = 0; i < 10; i++) {
            TF* temp = HT[i];
            cout << "a[" << i << "]: ";
            while (temp != NULL) {
                cout << "->" << temp->value;
                temp = temp->link;
            }
            cout << "\n";
        }
    }

    int searchData(int value) {
        int hash_val = Fn_hash(value);
        TF* entry = HT[hash_val];
        while (entry != NULL) {
            if (entry->value == value) {
                cout << "\nElement found at: ";
                cout << hash_val << ":" << entry->value << endl;
                return 1; // Element found
            }
            entry = entry->link;
        }
        cout << "Element not found." << endl;
        return 0; // Element not found
    }

    void deleteElement(int value) {
        int hash_val = Fn_hash(value);
        TF* entry = HT[hash_val];
        if (entry == NULL) {
            cout << "Element not found." << endl;
            return;
        }
        if (entry->value == value) {
            HT[hash_val] = entry->link;
            delete entry;
            cout << "Element deleted successfully." << endl;
            return;
        }
        while (entry->link != NULL && entry->link->value != value) {
            entry = entry->link;
        }
        if (entry->link == NULL) {
            cout << "Element not found." << endl;
            return;
        }
        TF* temp = entry->link;
        entry->link = temp->link;
        delete temp;
        cout << "Element deleted successfully." << endl;
    }

    void insertElement(int value) {
        int hash_val = Fn_hash(value);
        TF* head = new TF;
        head->value = value;
        head->link = NULL;
        if (HT[hash_val] == NULL) {
            HT[hash_val] = head;
        } else {
            TF* temp = HT[hash_val];
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = head;
        }
    }
};

int main() {
    int ch, data, search, del;
    Telephone h;
    do {
        cout << "\nTelephone: \n1. Insert \n2. Display \n3. Search \n4. Delete \n5. Exit";
        cout << "\nSelect your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter phone no. to be inserted: ";
                cin >> data;
                h.insertElement(data);
                break;
            case 2:
                h.print();
                break;
            case 3:
                cout << "\nEnter the no to be searched: ";
                cin >> search;
                h.searchData(search);
                break;
            case 4:
                cout << "\nEnter the phno. to be deleted: ";
                cin >> del;
                h.deleteElement(del);
                break;
        }
    } while (ch != 5);

    return 0;
}
