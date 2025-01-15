#include <iostream>
#include "patients.h"
using namespace std;

string patients::patient_Status()const 
{
    if (diagnosis.find("critical") != string::npos) 
    {
        return "Critical";
    }
    else if (diagnosis.find("moderate") != string::npos) 
    {
        return "Moderate";
    }
    else
    {
        return "Stable";
    }
}

void patients::print_Patient_Info() const
{
    cout << "Patient Info:" << "\n"
         << "Name: " << firstname << " " << lastname << "\n"
         << "ID: " << patientID << "\n"
         << "Assigned Doctor ID: " << (assigneddoctor == -1 ? "None" : to_string(assigneddoctor)) << "\n"
         << "Date of birth: " << birthday << "\n"
         << "Blood Type: " << bloodtype << "\n"
         << "Diagnosis: " << diagnosis << "\n"
         << "Admission Date: " << admission_date << "\n"
         << "Discharge Date: " << (discharge_date.empty() ? "None" : discharge_date) << "\n"
         << "Status: " << patient_Status() << "\n";
}

int patients::getage()
{
    string str = patients::getbirthday();
    int age = stoi(str);
}
