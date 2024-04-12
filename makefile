CC = g++
CFLAGS = -c -Wall
LDFLAGS =
INCLUDES = -I./src
SRCDIR = coba
OBJDIR = obj
BINDIR = bin

SUBDIRS := $(shell find $(SRCDIR) -type d)

SOURCES := $(wildcard $(SRCDIR)/**/*.cpp)

OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: $(BINDIR)/program

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

$(BINDIR)/program: $(OBJECTS) $(SRCDIR)/main.cpp
	$(CC) $(LDFLAGS) $(OBJECTS) $(SRCDIR)/main.cpp -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)/program

run: $(BINDIR)/program
	./$<

.PHONY: all clean run