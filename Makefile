CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11 -O2
DEPS = HashTable.h HashEntry.h Time.h Classes.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Tufts: main.o  HashEntry.o HashTable.o Time.o Classes.o
	$(CC) -o Tufts main.o HashEntry.o HashTable.o Time.o Classes.o
	
clean:
	rm -f *.o core* *~ Tufts