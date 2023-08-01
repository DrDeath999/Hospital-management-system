#include <iostream>
#include <vector>
using namespace std;

class Authentication {
private:
  string username = "xyz";
  string password = "1234";
  string u, p;
  bool x = false;

public:
  Authentication() { authenticate(); }
  void authenticate() {
    cout << "Enter username: ";
    cin >> u;
    cout << "Enter password: ";
    cin >> p;

    if (u == username && p == password) {
      return;
      true;
    } else {
      cout << "login and password combination is incorrect, try again" << endl;
      authenticate();
    }
  }

  // bool validate() { return x; }
};
class Hospital {
public:
  string name;
  string HospitalContact;
  string hospital_type;
  string hospital_description;
};

class Doctor : public Hospital {
public:
  string docName;
  string docMobileNo;
  string docAddress;
  string docType;
};

class Reservation : public Hospital {
public:
  string time;
  string day;
  string reasonforreservation;

  void Reserve() {
    cout << "Enter time for reservation HH-MM: ";
    cin >> time;
    cout << "Enter day for reservation DD-MM: ";
    cin >> day;
    cout << "Enter the reason for reservation: ";
    cin >> reasonforreservation;
    cout << endl;
  }
  void checkReservation() {
    cout << "Time: " << time << endl;
    cout << "Day: " << day << endl;
    cout << "Reason: " << reasonforreservation << endl;
  }
};

class Patient : public Reservation {
public:
  string name;
  string patient_id;
  int age;
  double mobile_no;
  string patient_address;
  Patient() {
    cout << "Enter patient name: " << endl;
    cin >> name;
    cout << "Enter patient ID: " << endl;
    cin >> patient_id;
    cout << "Enter patient age: " << endl;
    cin >> age;
    cout << "Enter patient mobile number: " << endl;
    cin >> mobile_no;
    cout << "Enter patient address: " << endl;
    cin >> patient_address;
    cout << name << " has been admitted as a patient" << endl;
  }

  void setName(string x) { name = x; }
  void setAge(int x) { age = x; }
  void setMobile_no(double x) { mobile_no = x; }
  void setAddress(string x) { patient_address = x; }
  void setPatient_ID(string x) { patient_id = x; }
};

class PatientHistory : public Reservation {
public:
};

class MedicalInventory {
public:
  string medName;
  string expiryDate;
  int amount;
  int medCost;
  string medType;
  string composition;
  ~MedicalInventory() {}
  void addMedicine() {
    cout << "Enter the name of the medicine: ";
    cin >> medName;
    cout << "Enter expiry date DD-MM-YY: ";
    cin >> expiryDate;
    cout << "Enter amount of the medicine(tablets): ";
    cin >> amount;
    cout << "Enter cost of the medicine: ";
    cin >> medCost;
    cout << "Enter type of the medicine: ";
    cin >> medType;
    cout << "Enter composition of the medicine: ";
    cin >> composition;
    cout << medName << " is added to the inventory" << endl;
  }
};

int main() {
  Authentication admin1;

  int choice;
  bool exitProgram = false;
  vector<Patient> patients;
  vector<MedicalInventory> medicines;
  vector<Doctor> doctors;

  while (!exitProgram) {
    cout << "=== Hospital Management Program ===" << endl;
    cout << "1. Reserve Appointment" << endl;
    cout << "2. Check Appointment" << endl;
    cout << "3. Add Medicine to Inventory" << endl;
    cout << "4. Create Patient" << endl;
    cout << "5. Delete Patient" << endl;
    cout << "6. Delete Medicine" << endl;
    cout << "7. Add Doctor" << endl;
    cout << "8. View Doctors" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      // Reserve Appointment functionality
      int patientIndex;
      cout << "Enter patient index: ";
      cin >> patientIndex;

      if (patientIndex >= 0 && patientIndex < patients.size()) {
        patients[patientIndex].Reserve();
      } else {
        cout << "Invalid patient index." << endl;
      }
      break;
    }
    case 2: {
      // Check Appointment functionality
      int patientIndex;
      cout << "Enter patient index: ";
      cin >> patientIndex;

      if (patientIndex >= 0 && patientIndex < patients.size()) {
        patients[patientIndex].checkReservation();
      } else {
        cout << "Invalid patient index." << endl;
      }
      break;
    }
    case 3: {
      // Add Medicine to Inventory functionality
      MedicalInventory medInventory;
      medInventory.addMedicine();
      medicines.push_back(medInventory);
      break;
    }
    case 4: {
      // Create Patient functionality
      Patient patient;
      patients.push_back(patient);
      break;
    }
    case 5: {
      // Delete Patient functionality
      if (!patients.empty()) {
        string patientName;
        cout << "Enter the name of the patient to delete: ";
        cin.ignore();
        getline(cin, patientName);

        bool found = false;
        for (auto it = patients.begin(); it != patients.end(); ++it) {
          if (it->name == patientName) {
            patients.erase(it);
            found = true;
            cout << "Patient '" << patientName << "' has been deleted." << endl;
            break;
          }
        }

        if (!found) {
          cout << "Patient not found." << endl;
        }
      } else {
        cout << "No patients in the list." << endl;
      }
      break;
    }

    case 7: {
      // Add Doctor functionality
      Doctor doctor;
      cout << "Enter doctor's name: ";
      cin.ignore();
      getline(cin, doctor.docName);
      cout << "Enter doctor's mobile number: ";
      cin >> doctor.docMobileNo;
      cout << "Enter doctor's address: ";
      cin.ignore();
      getline(cin, doctor.docAddress);
      cout << "Enter doctor's area of expertise: ";
      cin.ignore();
      getline(cin, doctor.docType);
      doctors.push_back(doctor);
      cout << "Doctor " << doctor.docName << " added successfully." << endl;
      break;
    }
    case 8: {
      // View Doctors functionality
      if (!doctors.empty()) {
        cout << "=== Doctors ===" << endl;
        for (const auto &doctor : doctors) {
          cout << "Name: " << doctor.docName << endl;
          cout << "Mobile Number: " << doctor.docMobileNo << endl;
          cout << "Address: " << doctor.docAddress << endl;
          cout << endl;
        }
      } else {
        cout << "There are no doctors in the list " << endl;
      }

      break;
    }
    case 9: {
      exitProgram = true;
      cout << "Exiting the program..." << endl;
      break;
    }
    default: {
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
    }

    cout << endl;
  }

  return 0;
}

