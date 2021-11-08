CC = gcc
FLAGS = -Wall -g
AR=ar 

all: mains maindloop maindrec loopd recursives recursived loops

loops:libclassloop.a

loopd:libclassloop.so

recursives:libclassrec.a

recursived:libclassrec.so

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
	
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
		
libclassloops.a: advancedClassificationLoop.o basicClassification.o 
	$(AR) -rcs libclassloops.a advancedClassificationLoop.o basicClassification.o

libclassrec.a: advancedClassificationRecursion.o basicClassification.o 
	$(AR) -rcs libclassrec.a advancedClassificationRecursion.o basicClassification.o

libclassrec.so: advancedClassificationRecursion.o basicClassification.o 
	$(CC) -shared -o libclassrec.so advancedClassificationRecursion.o basicClassification.o

libclassloops.so: advancedClassificationLoop.o basicClassification.o 
	$(CC) -shared -o libclassloops.so advancedClassificationLoop.o basicClassification.o

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
	
mains: main.o libclassrec.a
	$(CC) $(FLAGS) main.o libclassrec.a -lm -o mains
	
maindloop: main.o 
	$(CC) $(FLAGS) main.o ./libclassloops.so -lm -o maindloop
		
maindrec: main.o 
	$(CC) $(FLAGS) main.o ./libclassrec.so -lm -o maindrec
	
.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec
