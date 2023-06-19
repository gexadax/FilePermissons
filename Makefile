# область специфических параметров
EXEC = Chat
# конец области

.RECIPEPREFIX = >
.SUFFIXES:
.SUFFIXES: .cpp .o
CC = g++
CFLAGS = -c -Wall -std=c++17
SOURCES := $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
> $(CC) $(OBJECTS) -o $@

.cpp.o:
> $(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
> rm -rf $(OBJECTS)
