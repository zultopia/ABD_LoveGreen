CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = hello.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)