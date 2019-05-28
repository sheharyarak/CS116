#ifndef STRINGSPLITTER_H
#define STRINGSPLITTER_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string splitString(string theString,const char splitter)
{
    string stringArray [4];
    int i=0;
    stringstream ss(theString);
    while(ss.good())
    {   string substr;
        getline(ss,substr,splitter);
        stringArray[i]=substr;
        i++;
    }
    return stringArray;
}

#endif