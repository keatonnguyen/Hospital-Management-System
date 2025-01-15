#include <iostream>
#include "doctors.h"
using namespace std;

double doctors::calculate_salary()
{
    newsalary = salary + (salary*bonus);
    return newsalary;
}

void doctors::print_doctor_info() const
{
    cout << "Doctor Info:" << "\n"
         << "Name: " << firstname << " " << lastname << "\n"
         << "ID: " << doctorID << "\n"
         << "Assigned Patient ID: " << (assignedpatient == -1 ? "None" : to_string(assignedpatient)) << "\n"
         <<"Specialty: "<< specialty << "\n"
         << "Years of experience: " << experience << "\n"
         << "Base salary: " << salary << "\n"
         << "Performance bonus: " << bonus << "\n"
         << "Total salary: " << newsalary << "\n";
}


