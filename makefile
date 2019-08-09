$CC = gcc
$CCFLAGS =-g -Wall

all: part3

%.o : %.c %.h
	$(CC) $(CCFLAGS) -c $^ -o $@

part3 : part3.o heapSort_int.o heapSort_str.o insertionSort_int.o insertionSort_str.o mergeSort_int.o mergeSort_str.o quickSort_int.o quickSort_str.o \
		radixSort_int.o radixSort_str.o searchAlgorithms.o selectionSort_int.o selectionSort_str.o 
		$(CC) $(CCFLAGS) $^ -o $@


run:
	./part3

clean:
	rm part3 *.o