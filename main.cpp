#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <memory>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <utility>
using namespace std;

// Custom Exception
class PatientException : public runtime_error {
public:
    PatientException(string msg) : runtime_error(msg) {}
};

// Abstract Base Class
class Patient {
protected:
    int id, age;
    string name, disease, status;
    static int count;

public:
    // 1. Default Constructor
    Patient() : id(0), age(0), name("Unknown"),
               disease("Unknown"), status("Admitted") {
        count++;
    }

    // 2. Parameterized Constructor
    Patient(int i, string n, int a, string d)
        : id(i), age(a), name(n), disease(d),
          status("Admitted") {
        count++;
    }

    // 3. Delegating Constructor
    Patient(int i, string n)
        : Patient(i, n, 0, "Unknown") {}

    // 4. Copy Constructor
    Patient(const Patient &p)
        : id(p.id), age(p.age), name(p.name),
          disease(p.disease), status(p.status) {
        count++;
    }

    // 5. Move Constructor
    Patient(Patient &&p) noexcept
        : id(p.id), age(p.age),
          name(move(p.name)), disease(move(p.disease)),
          status(move(p.status)) {
        count++;
    }

    // Virtual Destructor
    virtual ~Patient() {
        count--;
    }

    int getID() const {
        return id;
    }

    string getName() const {
        return name;
    }

    // Function Overloading
    void updateStatus() {
        status = "Under Treatment";
    }

    void updateStatus(string s) {
        status = s;
    }

    // Abstract Function
    virtual void display() const = 0;

    // Static Function
    static int getCount() {
        return count;
    }

    // Friend Function
    friend void showPatient(const Patient &p);

    // Operator Overloading
    friend ostream& operator<<(ostream &out,
                               const Patient &p);
};

int Patient::count = 0;

// Inheritance
class InPatient : public Patient {
public:
    // Default Constructor
    InPatient() : Patient() {}

    // Parameterized Constructor
    InPatient(int i, string n, int a, string d)
        : Patient(i, n, a, d) {}

    // Delegating Constructor
    InPatient(int i, string n)
        : Patient(i, n) {}

    // Copy Constructor
    InPatient(const InPatient &p)
        : Patient(p) {}

    // Move Constructor
    InPatient(InPatient &&p) noexcept
        : Patient(move(p)) {}

    // Function Overriding
    void display() const override {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nAge: " << age
             << "\nDisease: " << disease
             << "\nStatus: " << status << endl;
    }
};

// Friend Function
void showPatient(const Patient &p) {
    cout << "\nPatient Name: " << p.name
         << "\nStatus: " << p.status << endl;
}

// Operator Overloading
ostream& operator<<(ostream &out, const Patient &p) {
    out << p.id << " " << p.name << " "
        << p.age << " " << p.disease << " "
        << p.status;
    return out;
}

// Template Function
template <class T>
void message(T msg) {
    cout << msg << endl;
}

int main() {
    vector<unique_ptr<Patient>> patients;
    map<int, Patient*> patientMap;
    int choice;

    do {
        cout << "\n===== CAREPASS =====";
        cout << "\n1. Add Patient";
        cout << "\n2. Display Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Update Status";
        cout << "\n5. Discharge Patient";
        cout << "\n6. Save Records";
        cout << "\n7. Load Records";
        cout << "\n8. Sort Patients";
        cout << "\n9. Patient Count";
        cout << "\n10. File Pointer Demo";
        cout << "\n11. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        try {
            // Add Patient
            if (choice == 1) {
                int id, age;
                string name, disease;

                cout << "Enter ID: ";
                cin >> id;

                if (patientMap.count(id))
                    throw PatientException("ID Already Exists!");

                cout << "Enter Name: ";
                cin >> name;

                cout << "Enter Age: ";
                cin >> age;

                cout << "Enter Disease: ";
                cin >> disease;

                auto p = make_unique<InPatient>(
                    id, name, age, disease);

                patientMap[id] = p.get();
                patients.push_back(move(p));

                message("Patient Added Successfully!");
            }

            // Display Patients
            else if (choice == 2) {
                if (patients.empty())
                    cout << "No Patients Available.";

                for (auto &p : patients)
                    p->display();
            }

            // Search Patient
            else if (choice == 3) {
                int id;

                cout << "Enter Patient ID: ";
                cin >> id;

                if (patientMap.count(id))
                    patientMap[id]->display();
                else
                    throw PatientException("Patient Not Found!");
            }

            // Update or Discharge
            else if (choice == 4 || choice == 5) {
                int id;

                cout << "Enter Patient ID: ";
                cin >> id;

                if (!patientMap.count(id))
                    throw PatientException("Patient Not Found!");

                if (choice == 4)
                    patientMap[id]->updateStatus();
                else
                    patientMap[id]->updateStatus("Discharged");

                message("Status Updated Successfully!");
            }

            // Save Records
            else if (choice == 6) {
                ofstream file("patients.txt");

                if (!file)
                    throw PatientException("File Cannot Open!");

                for (auto &p : patients)
                    file << *p << endl;

                file.close();
                message("Records Saved!");
            }

            // Load Records
            else if (choice == 7) {
                ifstream file("patients.txt");

                if (!file)
                    throw PatientException("File Not Found!");

                int id, age;
                string name, disease, status;

                while (file >> id >> name >> age
                            >> disease >> status) {

                    if (patientMap.count(id))
                        continue;

                    auto p = make_unique<InPatient>(
                        id, name, age, disease);

                    p->updateStatus(status);

                    patientMap[id] = p.get();
                    patients.push_back(move(p));
                }

                file.close();
                message("Records Loaded!");
            }

            // Lambda and Sorting
            else if (choice == 8) {
                sort(patients.begin(), patients.end(),
                    [](const unique_ptr<Patient> &a,
                       const unique_ptr<Patient> &b) {
                        return a->getID() < b->getID();
                    });

                message("Patients Sorted!");
            }

            // Static Member
            else if (choice == 9) {
                cout << "Total Patients: "
                     << Patient::getCount();
            }

            // File Pointer Functions
            else if (choice == 10) {
                fstream file("patients.txt",
                    ios::in | ios::out);

                if (!file) {
                    cout << "Save Records First!";
                }
                else {
                    file.seekp(0, ios::end);
                    cout << "Write Position: "
                         << file.tellp() << endl;

                    file.seekg(0, ios::beg);
                    cout << "Read Position: "
                         << file.tellg() << endl;

                    file.close();
                }
            }

            else if (choice == 11) {
                message("Thank You!");
            }

            else {
                cout << "Invalid Choice!";
            }
        }

        catch (const PatientException &e) {
            cout << "Error: " << e.what() << endl;
        }

        catch (const exception &e) {
            cout << "Exception: " << e.what() << endl;
        }

    } while (choice != 11);

    return 0;
}