CC=g++
CFLAGS=-c -Wall
LDFLAGS=
INCLUDES=-I./hello -I./world
HELLO_SRC=hello/hello.cpp
HELLO_OBJ=hello/hello.o
WORLD_SRC=world/world.cpp
WORLD_OBJ=world/world.o
MAIN_SRC=main.cpp
MAIN_OBJ=main.o
EXECUTABLE=program

all: $(HELLO_OBJ) $(WORLD_OBJ) $(MAIN_OBJ) $(EXECUTABLE)

$(EXECUTABLE): $(HELLO_OBJ) $(WORLD_OBJ) $(MAIN_OBJ)
	$(CC) $(LDFLAGS) $(HELLO_OBJ) $(WORLD_OBJ) $(MAIN_OBJ) -o $@

hello/hello.o: $(HELLO_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

world/world.o: $(WORLD_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

main.o: $(MAIN_SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf hello/*.o world/*.o $(MAIN_OBJ) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)