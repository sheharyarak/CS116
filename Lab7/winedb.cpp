/*

http://www.codingfriends.com/index.php/2010/02/17/mysql-connection-example/

To compile up this program you will need to link to the mysql libraries and headers that are used within the program, e.g. mysql.h at the top of the program. To gain access to these, there is a nice mysql_config (you may need to install it via your package manager system if you do not have it already).

Here are my outputs of what is required on the command line for the g++ compiler



g++ -I/usr/include/mysql winedb.cpp -o winedb -L/usr/lib/mysql -lmysqlclient


./windb "select * from wineInfo where price > 100"

*/

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "dbconnect.h"
#include <stdlib.h>  // atoi, atof

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
	    
  vector<Wine> wineList;
  
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
	
	printMeFirst();

  // assign the results return to the MYSQL_RES pointer
  if (argc < 2)
  {
     cout << "argv[0]: " << argv[0] << endl;
     printf("\nUsage: %s  \"SQL statement here\"\n", argv[0]);
     printf("if no argument given, default is:\n %s show tables\n", argv[0]);
     res = mysql_perform_query(conn, (char *)"show tables");
     printf("MySQL Tables in mysql database:\n");
  }
  else
  {
     // use wine database
     res = mysql_perform_query(conn, (char *)"use wine");
     cout << "argv[0]: " << argv[0] << endl;
     cout << "argv[1]: " << argv[1] << endl;
     res = mysql_perform_query(conn, argv[1]);
		
 
     while ((row = mysql_fetch_row(res)) !=NULL)
     {

	  num++;
      if (argc < 2) {
         printf("%s\n", row[0]);  // only print out 1st column
      }
      else
      {
		  /* print out each row of the data extracted from
		   * MySQL database
		   * Make sure the output is line up with the header
		   * Hint: use left and setw
		   * WineInfo table Fields:
		   *   Table Field 1 - row[0] - name (wine name price) 
		   *   Table Field 2 - row[1] - vintage (year of the wine)
		   *   Table Field 3 - row[2] - score (rating of the wine by experts)
		   *   Table Field 4 - row[3] - price (price of wine)
		   *   Table Field 5 - row[4] - wineryID (index to winery table)*******************
		   *   Table Field 6 - row[5] - type (red, white)
		   *   Table Field 7 - row[6] - location (where is the wine from)******************
		   *   Table Field 8 - row[7] - UPC (wine product code)****************************

	    * Add your code to put the wine into wineList vector
	    * 
	    * You need to define Wine wine variable and use constructor
	    * to initialize name, vintage, score, price and type
	    * ????
	    * atoi(string) - convert string to integer
	    * atof(string) - convert string to double
	    * Wine wine (row[0], atoi(row[1]), ??????????);
	    * wineList.??????(?????);  put wine into the wineList vector
	    */
		Wine wine(row[0],atoi(row[1]),atoi(row[2]),atof(row[3]),row[5]);
	    /*??? put wine into wineList vector ??? */ 
   		wineList.push_back(wine);
	  		
      } /* end else */
      /*
       * number of wine retrieved from mySQL and average price
       */
       totalPrice+=atof(row[3]);
    } /* end of while my_sql_fetch */
 
  /* clean up the database result set */
  mysql_free_result(res);
  /* clean up the database link */
  mysql_close(conn);
	
 
  /*
   * Using while loop (or do-while) to implement user menu to 
   * print out information from wine vector
   */
 
 
   cout <<"\nPrint out wine vector\n\n";  
   	        cout << setw(30) << "Wine Name"
            << setw(16)           << "Vintage"
			<< setw(12)			<< "Score"
			<< setw(12)			<< "Price" 
			<< setw(10)			<< "Type"
	 << endl;
	   
     cout << setw(30) << "---------"
            << setw(16)           << "-------"
			<< setw(12)			<< "------"
			<< setw(12)			<< "-----" 
			<< setw(10)			<< "----"
	 << endl;
	 
	 
 
   num=0;
   //totalPrice=0;
   
   /*
    * Add code below to print out all the wine info from
    * wineList using for loop to traverse the wineList vector
    *
   
    * for (int unsigned i=0; i < ?????? ; i++) 
    *  
    * As you print out each wineInfo from the weneList using 
    * printWineInfo(), you should
    * also add the totalPrice for all the wines in the vector so you 
    * can calculate average wine price
    */
	for(unsigned int i=0;i<wineList.size();i++){
	wineList[i].printWineInfo();
	}
   
   cout <<"Total number of wine found: " << wineList.size() << endl;
   cout <<"Average price: $"<< fixed << setprecision(2) 
		<< totalPrice/wineList.size() << endl;  
  }
  return 0;
}
