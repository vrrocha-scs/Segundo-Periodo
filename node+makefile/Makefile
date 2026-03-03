CC=g++
CFLAGS=-std=c++11 -Wall
SRC=src
BUILD=build
INCLUDE=include
EXEC=vpl_execution

all: $(EXEC)

$(BUILD)/list.o: $(INCLUDE)/list.hpp $(SRC)/list.cpp $(INCLUDE)/node.hpp
	$(CC) $(CFLAGS) -c $(SRC)/list.cpp -I$(INCLUDE) -o $(BUILD)/list.o

$(BUILD)/main.o: $(INCLUDE)/list.hpp $(SRC)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp -I$(INCLUDE)-o $(BUILD)/main.o

$(EXEC): $(BUILD)/list.o $(BUILD)/main.o
	$(CC) $(CFLAGS) $(BUILD)/list.o $(BUILD)/main.o -o $(EXEC)




