#ifndef DOCTORS_H
#define DOCTORS_H
#include <iostream>
using namespace std;

class doctors
{
private:
    string firstname;
    string lastname;
    long int doctorID;
    long int assignedpatient;
    int experience;
    double salary;
    double bonus;
    int newsalary;
    string specialty;

public:
    doctors()                           //DEFAULT CONSTRUCTOR
    {
        firstname = " ";
        lastname = " ";
        doctorID = 0;
        assignedpatient = 0;
        experience = 0;
        salary = 0.0;
        bonus = 0.0;
        specialty = " ";
    }

    doctors(string f, string l, long int d, long int a, double s, double b);

    string getfirstname()                                //GETTER FUNCTIONS
    {
        return firstname;
    }
    string getlastname()
    {
        return lastname;
    }
    long int getdoctorID()const
    {
        return doctorID;
    }
    long int getassignedpatient()
    {
        return assignedpatient;
    }
    int getexperience()
    {
        return experience;
    }
    double getsalary()
    {
        return salary;
    }
    double getbonus()
    {
        return bonus;
    }
    string getspecialty()const {
        return specialty;
    }

    void setfirstname(string f)                     //SETTER FUNCTIONS
    {
        firstname = f;
    }
    void setlastname(string l)
    {
        firstname = l;
    }    
    void setdoctorID(long int d)
    {
        doctorID = d;
    }
    void setassignedpatient(long int a)
    {
        assignedpatient = a;
    }
    void setexperience(int e)
    {
        experience = e;
    }

 
    double calculate_salary();

    void print_doctor_info ()const;

    void setspecialty(string sp){
        specialty=sp;
    }

};

#endif