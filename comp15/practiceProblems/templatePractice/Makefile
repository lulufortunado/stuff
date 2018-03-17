CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = LinkedList.h
 
 %.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)
 
listint: list-int.o LinkedList.o
	$(CC) -o listint list-int.o LinkedList.o

listdouble: list-double.o LinkedList.o
	$(CC) -o listdouble list-double.o LinkedList.o

clean:
	rm -f *.o core* *~ listint listdouble
