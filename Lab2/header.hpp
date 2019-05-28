#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee
{
    private:    //member variables
    string name;
    int idNumber;
    string department;
    string position;

    public: //mutator and accessor functions
    Employee(string eName, int eIdNumber, string eDepartment, string ePostion);
    Employee(string eName, int eIdNumber);
    Employee();
    
    string getName();
    int getIdNumber();
    string getDepartment();
    string getPosition();

    void setName(string eName);
    void setIdNumber(int eIdNumber);
    void setDepartment(string eDepartment);
    void setPosition(string ePosition);

};

Employee::Employee(string eName, int eIdNumber, string eDepartment, string ePosition)
{
    name = eName;
    idNumber = eIdNumber;
    department = eDepartment;
    position = ePosition;
}

Employee::Employee(string eName, int eIdNumber)
{
    name = eName;
    idNumber = eIdNumber;
    department = "";
    position = "";
}

Employee::Employee()
{
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

string Employee::getName()
{
    return name;
}
int Employee::getIdNumber()
{
    return idNumber;
}
string Employee::getDepartment()
{
    return department;
}
string Employee::getPosition()
{
    return position;
}

void Employee::setName(string eName)
{
    name = eName; //simply sets the attribute to the input in the parameter
}
void Employee::setIdNumber(int eIdNumber)
{
    idNumber = eIdNumber;
}
void Employee::setDepartment(string eDepartment)
{
    department = eDepartment;
}
void Employee::setPosition(string ePosition)
{
    position = ePosition;
}

void displayEmployee(Employee employee)
/*this function is not part of the class because of the way it is called in the driver function. The way its called suggests that it is function outside the class scope.*/
{
    cout<<"Name: "<<employee.getName()<<endl;
    cout<<"ID Number: "<<employee.getIdNumber()<<endl;
    cout<<"Department: "<<employee.getDepartment()<<endl;
    cout<<"Position: "<<employee.getPosition()<<endl<<endl;
}


#endif