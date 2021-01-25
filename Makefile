CC = g++

all: Driver

Driver.o: Driver.cpp
	$(CC) -c Driver.cpp

Kmeans.o: Kmeans.cpp
	$(CC) -c Kmeans.cpp

Driver: Driver.o Kmeans.o
	$(CC) Driver.o Kmeans.o -o Driver

clean:
	rm -rf *o Driver

run:
	./Driver