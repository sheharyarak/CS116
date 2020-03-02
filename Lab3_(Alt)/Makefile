# begin of Makefile
#
CC=g++
#
CFLAGS = -c -Wall # -I/usr/include/mysql
# LFLAGS = -L/usr/lib/mysql -lmysqlclient
# LFLAGS =
all: main
main: main.o Account.o Bank.o printMeFirst.o
	$(CC) main.o Account.o Bank.o printMeFirst.o -o main $(LFLAGS)
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
Account.o: Account.cpp Account.h
	$(CC) $(CFLAGS) Account.cpp
Bank.o: Bank.cpp Bank.h
	$(CC) $(CFLAGS) Bank.cpp
printMeFirst.o: printMeFirst.cpp
	$(CC) $(CFLAGS) printMeFirst.cpp
clean:
	rm *.o main
run:
	./main
#end of Makefile