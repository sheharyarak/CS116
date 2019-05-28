
#include <stdio.h>
#include <iomanip>
#include "wine.h"
#include <iostream>

using namespace std;


Wine::Wine()
{
	price = 0;
}
//consrtucts a wine
Wine::Wine(double wine_price, string wine_name)
{
	price = wine_price;
	wineName = wine_name;
}
Wine::Wine(string wine_name, int wine_vintage, int wine_score, 
  double wine_price, string wine_type)
{
	/* set class wine attributes to the parameters
	 * ????????
	 * wineName = wine_name;
	 * vintage = ????
	 * */
		wineName=wine_name;
		vintage=wine_vintage;
		score=wine_score;
		price=wine_price;
		type=wine_type;
}
string Wine::get_winename() const
{
	return wineName; 
}
void Wine::set_winename(string wine_name)
{
	wineName = wine_name;
}
int Wine::get_vintage()const
{
	return vintage;
}
void Wine::set_vintage(int wine_vintage)
{
	vintage = wine_vintage;
}
int Wine::get_score()const
{
	return score;
}
void Wine::set_score(int wine_score)
{
	score = wine_score;
}

/*
 * return wine price
 * */
 
double Wine::get_price()const
{
	return price;
}

/*
 * set wine price
 * */
void Wine::set_price(double wine_price)
{
	price = wine_price;
}

/*
 * print out wineInfo wineName, vintage, score, price and type
 * */

void Wine::printWineInfo() const
{
	/* implement this function.
	 * Use setw to format the output
	 * ????????
	 * cout << setw(30) << wineName ??????
	 * ????? */
		cout<<setw(30)<< wineName
		<<setw(16)<<vintage
		<<setw(12)<<score
		<<setw(12)<<price
		<<setw(12)<<type<<endl;
}
 
 
