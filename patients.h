#ifndef PATIENTS_H
#define PATIENTS_H
#include <iostream>
using namespace std;

class patients
{

private:

    string firstname;           //PATIENT ATTRIBUTES
    string lastname;
    long int patientID;
    long int assigneddoctor;
    string birthday;
    string bloodtype;
    string diagnosis;
    string admission_date;
    string discharge_date;

public:

    patients()                      //DEFAULT CONSTRUCTOR
    {
    firstname = " ";
    lastname = " ";
    patientID = 0;
    assigneddoctor = 0;
    birthday = " ";
    bloodtype = " ";
    diagnosis = " ";
    admission_date = " ";
    discharge_date = " ";        
    }

    patients(string f, string l, long int p, long int a, string b, string q, string d, string i, string o);

    string getfirstname()               //GETTER FUNCTIONS
    {
        return firstname;
    }
    string getlastname()
    {
        return lastname;
    }
    long int getpatientID() const
    {
        return patientID;
    }
    long int getassigneddoctor() const
    {
        return assigneddoctor;
    }
    string getbirthday()
    {
        return birthday;
    }
    string getbloodtype()
    {
        return bloodtype;
    }
    string getdiagnosis()
    {
        return diagnosis;
    }
    string getadmission_date()
    {
        return admission_date;
    }
    string getdischarge_date()
    {
        return discharge_date;
    }

    void setfirstname(string f)               //SETTER FUNCTIONS
    {
        firstname = f;
    }
    void setlastname(string l)
    {
        lastname = l;
    }
    void setpatientID(long int p) 
    {
        patientID = p;
    }
    void setassigneddoctor(long int a)
    {
        assigneddoctor = a;
    }
    void setbirthday(string b)
    {
        birthday = b;
    }
    void setbloodtype(string q)
    {
        bloodtype = q;
    }
    void setdiagnosis(string d)
    {
        diagnosis = d;
    }
    void setadmissiondate(string i)
    {
        admission_date = i;
    } 
    void setdischargedate(string o)
    {
        discharge_date = o;
    }

    string patient_Status() const;
    void print_Patient_Info()const;
    int getage();
};

#endif