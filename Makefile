#
# TODO: Move `libmongoclient.a` to /usr/local/lib so this can work on production servers
#
 
CC := g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/maquinat 
EJEC :=./p2
RUN :=./bin/maquinat ./MT01.txt

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -Wall -std=c++2a -g 
LIB := #-lsfml-graphics -lsfml-window -lsfml-system #-pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
INC :=-I include


$(TARGET): $(OBJECTS)  	
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)  
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) -c -o $@ $<" $(INC); $(CC) $(CFLAGS) $(INC) -c -o $@ $<

run:
	$(RUN)

debug:

	$(CC) $(CFLAGS) *

clean:
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

.PHONY: clean