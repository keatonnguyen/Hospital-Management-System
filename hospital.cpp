#include "hospital.h"
#include <iostream>
#include <fstream>


Hospital::Hospital() {

    patientList= new vector <patients>;
    doctorList = new vector <doctors>;
    loadPatients();
    loadDoctors();


}

Hospital:: ~Hospital(){
    delete patientList;
    delete doctorList;
}


void Hospital ::loadPatients(){
    ifstream file("patients.txt");
    if (!file) {
        cout <<"Failed to open patients.txt"<<"\n";
        return;
    }

   int num;
   file >> num;
   while (num--){
    string f,l,b,q,d,i,o;
    long int p,a;
    file >> f>>l>>p>>a>>b>>q>>d>>i>>o;
    patients patientRecord(f, l, p, a, b ,q, d, i, o);
    patientList->push_back(patientRecord);

   }

}

void Hospital::loadDoctors(){
    ifstream file("doctors.txt");
    if (!file) {
       cout<<"Failed to open doctors.txt"<< "\n";
       return;
}

    int num;
    file>> num;
    while (num--){
        string f,l,sp;
        long int d, a;
        int e; 
        double s,b;
        file >> f>>l>>d>>sp>>e>>s>>b;
        doctors doctorRecord (f,l,d,a,s,b);
        doctorRecord.setexperience(e);
        doctorRecord.setspecialty(sp);
        doctorList->push_back(doctorRecord);
    
    }
  
    }


    void Hospital::Find_Oldest_Patient(){
        if (patientList-> empty()){
        cout<< "No patients available.\n";
        return ;

    }
    patients* oldest = &(*patientList)[0];
    for (size_t i = 1; i< patientList->size(); ++i){
        if (patientList->at(i).getage()> oldest->getage()){
            oldest = &patientList->at(i);
        }
    }
    cout << "Oldest patient details: \n";
    oldest ->print_Patient_Info();
    }


    int Hospital:: Count_Critical_Patients(){
        int count=0;
        for(const auto& patientRecord : *patientList){
            if(patientRecord.patient_Status()== "Critical" ){
                ++count;
            }
        }
        return count;
    }

    void Hospital ::Doctors_By_Specialty(const string &specialty){
        bool found = false;
        for (const auto &doctorRecord : *doctorList){
                doctorRecord.print_doctor_info();
                found = true;

        }

    }

    void Hospital::Show_Patient_by_ID(long int id){
        for (const auto& patientRecord : *patientList){
            if(patientRecord.getpatientID()==id){
                patientRecord.print_Patient_Info();
            }
        }
        cout <<"No patient has the provided ID.\n";
    }

    void Hospital::Show_Doctor_by_ID(long int id){
        for (const auto& doctorRecord : *doctorList){
            if(doctorRecord.getdoctorID()==id){
                doctorRecord.print_doctor_info();
            }
        }
        cout <<"No patient has the provided ID.\n";
    }

    void Hospital ::Show_assigned_doctor(long int patientID){
        for (const auto& patientRecord: *patientList){
            if (patientRecord.getpatientID()== patientID){
                if (patientRecord.getassigneddoctor() != -1){
                    Show_Doctor_by_ID(patientRecord.getassigneddoctor());
                }
                else{cout << "This patient has no assigned doctor.\n";
                }
                return;
            }
        }
            cout<<"No patient has the provided ID.\n";
    }

    void Hospital ::show_Assigned_Patients(long int doctorID){
        bool found = false;
        for (const auto&patientRecord : *patientList){
            if (patientRecord.getassigneddoctor()== doctorID){
                patientRecord.print_Patient_Info();
                found = true;
            }
        }
        if (!found) cout <<"No patients assigned.\n";
    }