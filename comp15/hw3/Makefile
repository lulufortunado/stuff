CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = Stack.h RPNCalc.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

calculator: run-calc.o RPNCalc.o Stack.o
	$(CC) -o calculator run-calc.o RPNCalc.o Stack.o

clean:
	rm -f *.o core* *~ run-calc

stacktest: test-stack.o RPNCalc.o Stack.o
	$(CC) -o stacktest test-stack.o RPNCalc.o Stack.o
