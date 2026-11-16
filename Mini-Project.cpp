#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Patient {
private:
    int id, age;
    string name, disease, status;

public:
    Patient(int i, string n, int a, string d) {
        id = i;
        name = n;
        age = a;
        disease = d;
        status = "Admitted";
    }

    int getID() {
        return id;
    }

    void display() {
        cout << "\nPatient ID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nCondition: " << disease;
        cout << "\nStatus: " << status << endl;
    }

    void updateStatus(string s) {
        status = s;
    }

    void save(ofstream &file) {
        file << id << "," << name << "," << age
             << "," << disease << "," << status << endl;
    }
};

int main() {
    vector<Patient> patients;
    int choice;

    do {
        cout << "\n===== CAREPASS =====";
        cout << "\n1. Add Patient";
        cout << "\n2. Display Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Update Patient Status";
        cout << "\n5. Discharge Patient";
        cout << "\n6. Save Records";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, age;
            string name, disease;

            cout << "Enter Patient ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Condition: ";
            cin >> disease;

            patients.emplace_back(id, name, age, disease);
            cout << "Patient added successfully!";
        }

        else if (choice == 2) {
            if (patients.empty())
                cout << "No patients available.";

            for (auto &p : patients)
                p.display();
        }

        else if (choice == 3) {
            int id;
            bool found = false;

            cout << "Enter Patient ID: ";
            cin >> id;

            for (auto &p : patients) {
                if (p.getID() == id) {
                    p.display();
                    found = true;
                }
            }

            if (!found)
                cout << "Patient not found.";
        }

        else if (choice == 4 || choice == 5) {
            int id;
            bool found = false;

            cout << "Enter Patient ID: ";
            cin >> id;

            for (auto &p : patients) {
                if (p.getID() == id) {
                    if (choice == 4)
                        p.updateStatus("Under Treatment");
                    else
                        p.updateStatus("Discharged");

                    cout << "Status updated successfully!";
                    found = true;
                }
            }

            if (!found)
                cout << "Patient not found.";
        }

        else if (choice == 6) {
            ofstream file("patients.txt");

            for (auto &p : patients)
                p.save(file);

            file.close();
            cout << "Records saved successfully!";
        }

    } while (choice != 7);

    return 0;
}
