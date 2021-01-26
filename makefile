BIN=./bin/
SOURCE=./src/
INCLUDE=./include/


all: bank

bank: ioUtils.o bank.o bankAPI.o file_action.o 
	gcc -g -Wall -o bank $(BIN)/bank.o $(BIN)/ioUtils.o $(BIN)/bankAPI.o $(BIN)/file_action.o

ioUtils.o: $(SOURCE)/ioUtils.c  $(INCLUDE)/ioUtils.h
	gcc -g -Wall -c $(SOURCE)/ioUtils.c -o $(BIN)/ioUtils.o 

bank.o: $(SOURCE)/bank.c 
	gcc -g -Wall -c $(SOURCE)/bank.c -o $(BIN)/bank.o 

bankAPI.o: $(SOURCE)/bankAPI.c $(INCLUDE)/bankAPI.h
	gcc -g -Wall -c $(SOURCE)/bankAPI.c -o $(BIN)/bankAPI.o

file_action.o: $(SOURCE)/file_action.c $(INCLUDE)/file_action.h
	gcc -g -Wall -c $(SOURCE)/file_action.c -o $(BIN)/file_action.o

.PHONY: clean run

clean:
	rm -vf bank $(BIN)/*

run:
	./bank

	
