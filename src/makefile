CC=g++
CFLAGS= -Wall -g
LDFLAGS=
DIR = "\src"
BUILD = "\build"
SRC = $(wildcard *.cpp)
HEADER = $(wildcard *.h)
OBJ = $(SRC:.cpp=.o)

EXEC=SchoolClassCalculator

all: $(EXEC)

$(BUILD):
	mkdir build

%.o: %.cpp $(HEADER)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	echo "Compile"
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean oclean

clean:
	@echo "Clean"
	@(rm -rf $(EXEC))
	@(rm -rf *.h.gch)
	@(rm -rf *.o)

oclean: $(EXEC)
	@(rm -rf *.o)
