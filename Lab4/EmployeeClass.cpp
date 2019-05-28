/**
 *TODO:The purpose of this program is to keep track of employee information such as name, ID number, Departmant, and position
 @param name - Sheharyar Khan
 @param courseInfo - CS-116
 @return - none
*/
#include <vector>//including vector library to use vectors
#include <iostream>
#include "EmployeeHeader.hpp" //using a header file for the class and the functions
#include "printmefirst.hpp" //using a separate header file for the print me first function as it will probably be used in every project for this course and this would be easier than copying the code over and over again. I also wanted to apply what I learned today in class
#include <sstream>//using the stringstream library for stringstream objects
#include <fstream> //using fstream library to read and write to files

using namespace std;

int main()
{
 printMeFirst ("Sheharyar Khan", "CS - 116: Lab 2"); //put your name instead of “Ron Sha”
 // Create an Employee object
Employee X;
//define character that splits data in the text file
const char SPLIT_CHAR = ';';
//define file path
string fileName="Employee.txt";
//declare vector
vector <Employee> employeeList;
//declaring Substring
string subString;
//declaring input file stream
ifstream textFile;
textFile.open(fileName);
//if the file is open then run the loop else tell the user the file failed to open
if(textFile.is_open())
{
    while(textFile.good())
    {//in the text file get a substring till the end of line character
        getline(textFile, subString);
        string stringArray [4];
        int i=0;
        stringstream ss(subString);
        while(ss.good())
        {   string substr;
        //in the substring get a sub-substring till the splitting character
            getline(ss,substr,SPLIT_CHAR);
            //add sub-substring to array
            stringArray[i]=substr;
            i++;
        }
        //convert string to int by using >> operator, basically using cin to define the variable but instead of the console input we're using a string
        stringstream idNum(stringArray[1]);
        int idNumInt;
        idNum >> idNumInt;
        //calling operater constructor and creating employee x
        Employee X(stringArray[0],idNumInt,stringArray[2],stringArray[3]);
        //adding employee x to the vector
        employeeList.push_back(X);
    }
    //couting list headings and dividers
    cout<<"Name \t \t ID \t Dept \t \t Position"<<endl;
    cout<<"---- \t \t -- \t ---- \t \t --------"<<endl;

    //couting all the employees in the vector
    for(int i =0;i<employeeList.size();i++)
    {
        cout<<employeeList[i]<<endl;
    }
}
else 
{//if file fails to open then...
    cout<<"ERROR! The text file failed to open."<<endl;
    return -1;
}
 return 0;
}