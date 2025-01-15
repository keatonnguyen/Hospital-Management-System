#include <iostream>
#include <vector>
#include "patients.h"
#include "doctors.h"

using namespace std;

class Hospital{
    private:
        vector<patients> *patientList;
        vector<doctors> *doctorList;

    public:
    
    Hospital();
    ~Hospital();

    void loadPatients();
    void loadDoctors();
    void Find_Oldest_Patient();
    int Count_Critical_Patients();
    void Doctors_By_Specialty(const string &specialty);
    void Show_Patient_by_ID(long int id);
    void Show_Doctor_by_ID(long int id);
    void Show_assigned_doctor(long int patientID);
    void show_Assigned_Patients(long int doctorID);
   
};