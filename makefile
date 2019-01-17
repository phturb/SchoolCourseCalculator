CC=g++
CFLAGS= -Wall -g
LDFLAGS=
#source files dir
SRCDIR = src
#object files dir
OBJDIR = obj
#executable files dir
BINDIR = bin

SRC = $(wildcard $(SRCDIR)/*.cpp)
HEADER = $(wildcard $(SRCDIR)/*.h)
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
#PROJECT NAME
PROJECT=SCC

#Executable
EXEC=$(BINDIR)/$(PROJECT)

#Make All
all: $(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

#Make the files dir
$(shell mkdir -p $(BINDIR))
$(shell mkdir -p $(OBJDIR))

.PHONY: clean oclean full run

#Clean all files created by the make
clean:
	@echo "Clean"
	@(rm -rf $(BINDIR))
	@(rm -rf src/*.h.gch)
	@(rm -rf $(OBJDIR))

#Clean before remaking
full: clean all

#Clean the objects when the make is run
oclean: $(EXEC)
	@(rm -rf obj/*.o)

#Run at the end of the make
run: $(EXEC)
	@(./$(EXEC))

gitadd: clean
	@(git add .)
