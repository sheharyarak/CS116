#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

class Money
{   
    private:
    //member variables
    double value;
    int dollars;
    int cents;
    //private member functions
    void simplify();
    void distribute();
    void combine();

    public:
    //constructors
    Money(double money);
    Money(int d, int c);
    Money();
    
    void setValue(int d, int c);//mutator
    double getValue() const;//accessor

    //operators
    double operator+    (Money const &right);
    double operator-    (Money const &right);
    double operator*    (double const &right);
    bool operator==    (Money const &right);
    bool operator>     (Money const &right);
    bool operator<     (Money const &right);
    Money operator= (double const &right);
};

//Definitions
//*constructors
    Money::Money(int d, int c)
    {
        dollars = d;
        cents = c;
        simplify();
    }

    Money::Money(double input)
    {
        value=input;
        distribute();
    }

    Money::Money()
    {
        value = 0;
        distribute();
    }
//*private methods
    void Money::combine()
    {
        value = dollars*100; //$8 becomes 800
        value+= cents;//adding 35 cents you get 835
        value = value/100;//you get 8.35
    }

    void Money::distribute()
    {
        double temp = value;
        dollars = floor(temp);//assuming value equals 8.35 this will set dollars to 8 as flooring would ignore everything after the decimal
        cents = (value*100)-(dollars*100);//8.35 becomes 835 and 8 becomes 800. 835-800 = 35 and we set that equal to the cents
        simplify();
    }

    void Money::simplify()
    {   
        if(cents<0)
        {
            dollars-=1;//we borrow one dollar like we borrow in basic subraction
            cents = 100 + cents;//adding because cents is already negative and +*- = -
        }
        else if(cents>=100)
        {
            dollars+=1;//carries over 1 to the next digit like in simple addition
            cents-=100;// subracts 100 because we basically carried that over
        }
        combine();
        
    }
//*public methods
    void Money::setValue(int d, int c)
    {
        dollars = d;
        cents = c;
        simplify();
    }

    double Money::getValue() const
    {
        return value;
    }

//overloaded operators
    double Money::operator+    (Money const &right)
    {
       return value+right.value; //adds value variables
    }

    double Money::operator-    (Money const &right)
    { 
        return value-right.value; //calculates the difference between the value variables
    }
    
    double Money::operator*    (double const &right)
    {
        return value*right; //multiplies the value variable
    }

    bool Money::operator==    (Money const &right)
    {
        if(value==right.value)//compares the value variable
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Money::operator>     (Money const &right)
    {
        if(value>right.value)//compares the value variable
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Money::operator<     (Money const &right)
    {
        if (value<right.value)//compares the value variable
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Money Money::operator= (double const &right)
    {   
        //sets the value variable then distributes it
        value = right; 
        distribute();
    }

//cout function
    std::ostream& operator<< (std::ostream& output, Money const &right)
        {   //             setting the number of decimal places
            output << "$"<<setprecision (2) << fixed<<right.getValue();
            return output;
        }
        
#endif