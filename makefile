CC=g++
CFLAGS= -Wall -g
LDFLAGS=
SRCDIR = src
OBJDIR = obj
BINDIR = bin
SRC = $(wildcard $(SRCDIR)/*.cpp)
HEADER = $(wildcard $(SRCDIR)/*.h)
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
EXEC=SCC

all: $(EXEC)

run: $(EXEC)
	@(./$(EXEC))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.PHONY: clean oclean

clean:
	@echo "Clean"
	@(rm -rf $(EXEC))
	@(rm -rf src/*.h.gch)
	@(rm -rf obj/*.o)

oclean: $(EXEC)
	@(rm -rf obj/*.o)
