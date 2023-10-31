
all: phonebook
		
phonebook: Mini5main.o Mini5phone.o 
	gcc -o phonebook Mini5phone.o Mini5main.o 

Mini5phone.o: Mini5phone.c Mini5phone.h
	gcc -c Mini5phone.c
      


Mini5main.o: Mini5main.c Mini5phone.h
	gcc -c Mini5main.c



backup:
	rm -f Mini5main *.o

