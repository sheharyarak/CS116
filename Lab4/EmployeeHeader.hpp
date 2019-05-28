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
    //Parameters:    Name       idNumber          Department          Position
    //these parameters are assigned to the member variables
    Employee(string eName, int eIdNumber, string eDepartment, string ePostion);
    //Parameters:    Name       idNumber
    //these parameters are assigned to the member variables
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
          //Parameters:    Name       idNumber          Department          Position
         //these parameters are assigned to the member variables
Employee::Employee(string eName, int eIdNumber, string eDepartment, string ePosition)
{
    name = eName;
    idNumber = eIdNumber;
    department = eDepartment;
    position = ePosition;
}
          //Parameters:    Name       idNumber
         //these parameters are assigned to the member variables
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

//returns the name
string Employee::getName()
{
    return name;
}
//returns the idnumber
int Employee::getIdNumber()
{
    return idNumber;
}
//returns the department
string Employee::getDepartment()
{
    return department;
}
//returns the position
string Employee::getPosition()
{
    return position;
}
//sets the name. @param eName - gets the name and assigns it to the member variable name
void Employee::setName(string eName)
{
    name = eName; //simply sets the attribute to the input in the parameter
}
//sets the IdNumber. @param eIdNumber - gets the IdNumber and assigns it to the member variable IdNumber
void Employee::setIdNumber(int eIdNumber)
{
    idNumber = eIdNumber;
}
//sets the Department. @param eDepartment - gets the Department and assigns it to the member variable Department
void Employee::setDepartment(string eDepartment)
{
    department = eDepartment;
}
//sets the Position. @param ePosition - gets the Position and assigns it to the member variable Position
void Employee::setPosition(string ePosition)
{
    position = ePosition;
}
//displays the Employee's Info by a series of cout statements
void displayEmployee(Employee employee)
/*this function is not part of the class because of the way it is called in the driver function. The way its called suggests that it is function outside the class scope.*/
{
    cout<<"Name: "<<employee.getName()<<endl;
    cout<<"ID Number: "<<employee.getIdNumber()<<endl;
    cout<<"Department: "<<employee.getDepartment()<<endl;
    cout<<"Position: "<<employee.getPosition()<<endl<<endl;
}
//overloaded << operator
//I overloaded this operator for practice. it was not really needed as the displayEmployee function could be overloaded or changed to produce the same result just by changing "endl;" to a tab "\t".
//this function overloaded in the same way as the overloaded operator in my money class but a brief summary would be:
//first I load everything into the output stream variable 'output' then return it ro the cout statement in the main code and that prints it out to the console.
//cout function
    std::ostream& operator<< (std::ostream& output, Employee &right)
        {    
            //using an if else branch to align the list if one of the departments is too short such as "IT" using "\t"
            if(right.getDepartment().length()<5){
                output<<right.getName()<<"\t"<<right.getIdNumber()<<"\t"<<right.getDepartment()<<"\t \t"<<right.getPosition();
            }else{
            output<<right.getName()<<"\t"<<right.getIdNumber()<<"\t"<<right.getDepartment()<<"\t"<<right.getPosition();
            }
            return output;
        }

#endif