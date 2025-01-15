#include <iostream>
#include "hospital.h"
#include <fstream>

using namespace std; 

void displayMenu() {
    cout << "\nHospital Management System:\n";
    cout << "1. Find the oldest patient\n";
    cout << "2. Report the number of critical patients\n";
    cout << "3. Show patient data by ID\n";
    cout << "4. Show doctor data by ID\n";
    cout << "5. Show the assigned doctor for a given patient\n";
    cout << "6. Show assigned patients for a given doctor\n";
    cout << "7. Exit the program\n";
    cout << "Enter your choice: ";
}

bool isValidID(long int id) {
    return id > 9999999 && id <= 99999999; // Validates an 8-digit ID
}


int main (){
    try {
        ifstream patientsFile("patients.txt");
        ifstream doctorsFile("doctors.txt");

        if (!patientsFile.is_open()) {
            cout << "Error: Failed to open patients.txt" << endl;
            return 1;
        }

        if (!doctorsFile.is_open()) {
            cout << "Error: Failed to open doctors.txt" << endl;
            return 1;
        }

        Hospital hospital;
        int choice;

        do {
            displayMenu();
            cin >> choice;

            switch (choice) {

                case 1: {
                hospital.Find_Oldest_Patient();
                break;
                }

                case 2: {
                int criticalCount = hospital.Count_Critical_Patients();
                cout << "Number of critical patients: " << criticalCount ;
                break;
                }

                case 3: {
                cout << "Enter patient ID: ";
                long int patientID;
                cin >> patientID;
                if (isValidID(patientID)) {
                hospital.Show_Patient_by_ID(patientID);
                } 
                else {
                cout << "Invalid ID format. Please enter an 8 digit ID.";
                    }
                break;
                }

                case 4: {
                cout << "Enter doctor ID: ";
                long int doctorID;
                cin >> doctorID;
                if (isValidID(doctorID)) {
                hospital.Show_Doctor_by_ID(doctorID);
                    }
                else {
                    cout << "Invalid ID format. Please enter an 8 digit ID.";
                }
                break;
                }

                case 5: {
                cout << "Enter patient ID: ";
                long int patientID;
                cin >> patientID;
                if (isValidID(patientID)) {
                try {
                hospital.Show_assigned_doctor(patientID);
                } 
                catch (...) {
                cout << "Error: The patient is not assigned to a doctor.";
                }
                }
                else {
                cout << "Invalid ID format please enter an 8-digit ID.";
                    }
                break;
                }

                case 6: {
                    cout << "Enter doctor ID: ";
                    long int doctorID;
                    cin >> doctorID;
                    if (isValidID(doctorID)) {
                    try {
                    hospital.show_Assigned_Patients(doctorID);
                    } 
                    catch (...) {
                    cout << "Error: No patients are assigned to this doctor.";
                        }
                    } 
                    else {
                    cout << "Invalid ID format please enter an 8 digit ID." ;
                    }
                    break;
                }

                case 7: {
                cout << "Exiting the program. Goodbye!" ;
                break;
                }

                default: {
                cout << "Invalid option please try again." ;
                break;
                }
            }
        } while (choice != 7);

    } catch (...) {
        cout << "unexpected error!" << endl;
    }

    return 0;
}