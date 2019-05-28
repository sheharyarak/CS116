
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "dbconnect.h"
#include <stdlib.h>  // atoi, atof
#include <sstream> //ostringstream

using namespace std;
 
#include "wine.h"
#include <iomanip>

using namespace std;

 
/*
 argv[1] - put sql command in argv[1], otherwise, just 
 use sql "show tables"
*/
int main(int argc, char* argv[])
{
  
  	  int num=0;
	  double totalPrice=0;
  
  MYSQL *conn;		// the connection
  MYSQL_RES *res;	// the results
  MYSQL_ROW row;	// the results row (line by line)
 
  struct connection_details mysqlD;
  mysqlD.server = (char *)"localhost";  // where the mysql database is
  mysqlD.user = (char *)"root";		// the root user of mysql	
  mysqlD.password = (char *)"password"; // the password of the root user in mysql
  mysqlD.database = (char *)"mysql";	// the databse to pick
 
  // connect to the mysql database
  conn = mysql_connection_setup(mysqlD);
  res = mysql_perform_query(conn, (char *)"use wine");

  
  ostringstream cmd;
  double price = 100;
     
     //construct SQL statement
     // cmd << "select * from wineInfo where price >= " << price;
     // This will put the SQL select statement into the cmd string
     //
     
	 cmd << "select * from wineInfo where price >= " << price; // construct SQL 
     
     res = mysql_perform_query(conn,  (char *) cmd.str().c_str());
     /*
      * you need to print out the header.  Make sure it it 
      * nicely formated line up.  Modify the cout statement
      * below so the header is nicely line up.  Hint: use left and setw
      * 
      * WineName   Vitange  Rating  Price  Type
      * */
     cout << setw(25) << "Wine Name"
            << setw(16)           << "Vintage"
			<< setw(12)			<< "Score"
			<< setw(12)			<< "Price" 
			<< setw(10)			<< "Type"
	 << endl;
     cout << setw(25) << "---------"
            << setw(16)           << "-------"
			<< setw(12)			<< "------"
			<< setw(12)			<< "-----" 
			<< setw(10)			<< "----"
	 << endl;

  while ((row = mysql_fetch_row(res)) !=NULL)
  {
	  num++;

		  /* print out each row of the data extracted from
		   * MySQL database
		   * Make sure the output is line up with the header
		   * Hint: use left and setw
		   * WineInfo table Fields:
		   *   1 - name (wine name price)
		   *   2 - vintage (year of the wine)
		   *   3 - score (rating of the wine by experts)
		   *   4 - price (price of wine)
		   *   5 - wineryID (index to winery table)
		   *   6 - type (red, white)
		   *   7 - location (where is the wine from)
		   *   8 - UPC (wine product code)
		   */

	 cout << setw(30) << row[0]   // coulumn (field) #1 - Wine name
	  << setw(10) << row[1] << "  " // field #2 - Vintage
	  << setw(10) << row[2] << "  " // field #3 - score
	 << setw(10) << row[3] << "  " // field #4 - price
	  << setw(10) << row[5] << "  " // field #6 - wine type
	  << endl;  	  
	 totalPrice = totalPrice + atof(row[3]); 
	  		
  } // end of while mysql
  
  

  cout <<"Total number of wine found: " << num << endl;
  cout <<"Average price: "<<totalPrice/num << endl;

  
  /* clean up the database result set */
  mysql_free_result(res);
  /* clean up the database link */
  mysql_close(conn);
 
  return 0;
}
