CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = Planet.h LinkedList.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

planets: planet-driver.o Planet.o LinkedList.o
	$(CC) -o planets planet-driver.o Planet.o LinkedList.o

clean:
	rm -f *.o core* *~ planet-driver

test: test-driver.o Planet.o LinkedList.o
	$(CC) -o test test-driver.o Planet.o LinkedList.o
