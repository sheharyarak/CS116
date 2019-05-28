#ifndef CCC_WINE_H
#define CCC_WINE_H

using namespace std;

class Wine
{
private:
//this is data information with five items winename, vintage, score, price and winearyname,
// I am not clearly understand winerayname, so I use the initializes of words from the wine information web you give us.
         string wineName;
         int vintage;
         int score;
         double price;
         string type;
public:
//this is constructs a defalut wine and a wine with price and name and a wine consturctor with name vintage score price and winearyname.
         Wine();
         Wine(double wine_price, string wine_name);
         Wine(string wine_name, int wine_vintage, int wine_score, 
         double wine_price, string type);
//this is get in this wine object
         string get_winename() const;
         int get_vintage()const;
         int get_score()const;
         double get_price()const;
//this is set of this wine object
         void set_winename(string wine_name);
         void set_vintage(int wine_vintage);
         void set_score(int wine_score);
         void set_price(double wine_price);
	 void printWineInfo() const; 
       
};

void printMeFirst(){
	cout<<endl;
	cout<<"Program written by - Sheharyar Khan"<<endl;
	cout<<"Course Info - CS-116"<<endl;
	time_t now = time(0);
	char* dt = ctime(&now);
	cout<<" Date: "<<dt<<endl;
}

#endif      
