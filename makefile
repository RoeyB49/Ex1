CC = gcc
FLAGS = -Wall -g
AR=ar 

all: mains maindloop maindrec libclassloops.a libclassrec.a libclassrec.so libclassloops.so
		
libclassloops.a: advancedClassificationLoop.o basicClassification.o NumClass.h
	$(AR) -rcs libclassloops.a advancedClassificationLoop.o basicClassification.o

libclassrec.a: advancedClassificationRecursion.o basicClassification.o NumClass.h
	$(AR) -rcs libclassrec.a advancedClassificationRecursion.o basicClassification.o
 
libclassrec.so: advancedClassificationRecursion.o basicClassification.o NumClass.h
	$(CC) -shared -o libclassrec.so advancedClassificationRecursion.o basicClassification.o

libclassloops.so: advancedClassificationLoop.o basicClassification.o NumClass.h
	$(CC) -shared -o libclassloops.so advancedClassificationLoop.o basicClassification.o

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
	
mains: main.o libclassrec.a
	$(CC) $(FLAGS) main.o libclassrec.a -lm -o mains
	
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) main.o libclassloops.so -lm -o maindloop
		
maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) main.o libclassrec.so -lm -o maindrec
	
.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec
