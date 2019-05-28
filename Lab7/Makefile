#
#
CC=g++
#
CFLAGS = -c -Wall -I/usr/include/mysql 
LFLAGS = -L/usr/lib/mysql -lmysqlclient



all: winedb sqlcommand

winedb: winedb.o dbconnect.o wineInfo.o
	$(CC) winedb.o wineInfo.o dbconnect.o -o winedb $(LFLAGS)

dbconnect.o: dbconnect.cpp
	$(CC) $(CFLAGS) dbconnect.cpp

winedb.o: winedb.cpp
	$(CC) $(CFLAGS) winedb.cpp

wineInfo.o: wineInfo.cpp
	$(CC) $(CFLAGS) wineInfo.cpp

sqlcommand: sqlcommand.o dbconnect.o wineInfo.o
	$(CC) sqlcommand.o wineInfo.o dbconnect.o -o sqlcommand $(LFLAGS)


sqlcommand.o: sqlcommand.cpp
	$(CC) $(CFLAGS) sqlcommand.cpp
clean:
	rm *.o winedb

run:
	./winedb "select * from wineInfo where price > 100"
