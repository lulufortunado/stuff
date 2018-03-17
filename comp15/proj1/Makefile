CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = BinaryTree.h BinarySearchTree.h Tree.h Survivor.h Queue.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

survivor: survivor-driver.o Survivor.o BinarySearchTree.o BinaryTree.o Queue.o
	$(CC) -o survivor survivor-driver.o Survivor.o BinarySearchTree.o \
															BinaryTree.o Queue.o

clean:
	rm -f *.o core* *~ survivor-driver

bst-driver-test: test-bst-driver.o Survivor.o BinarySearchTree.o BinaryTree.o \
																		Queue.o
	$(CC) -o bst-driver-test test-bst-driver.o Survivor.o BinarySearchTree.o \
															BinaryTree.o Queue.o

bt-driver-test: test-bt-driver.o Survivor.o BinarySearchTree.o BinaryTree.o \
																	Queue.o
	$(CC) -o bt-driver-test test-bt-driver.o Survivor.o BinarySearchTree.o \
															BinaryTree.o Queue.o

more-files-test: test-more-files-driver.o Survivor.o BinarySearchTree.o \
															BinaryTree.o Queue.o
	$(CC) -o more-files-test test-more-files-driver.o Survivor.o \
										 BinarySearchTree.o BinaryTree.o Queue.o


