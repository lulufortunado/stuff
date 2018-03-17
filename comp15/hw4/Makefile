CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = Heap.h MinHeap.h MaxHeap.h Patient.h 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

heaps: intake.o Patient.o Heap.o MinHeap.o MaxHeap.o
	$(CC) -o heapify intake.o Patient.o Heap.o MinHeap.o MaxHeap.o

clean:
	rm -f *.o core* *~ intake

min-heap-test: test-min-heap.o Patient.o Heap.o MinHeap.o MaxHeap.o
	$(CC) -o min-heap-test test-min-heap.o Patient.o Heap.o MinHeap.o MaxHeap.o

heap-test: heap-test.o Patient.o Heap.o MinHeap.o MaxHeap.o
	$(CC) -o heap-test heap-test.o Patient.o Heap.o MinHeap.o MaxHeap.o


