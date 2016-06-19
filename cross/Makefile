CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra
INCLUDES = header.h
SOURCES = main.c print_cross.c print_char.c
OBJECTS = $(SOURCES:.c=.o)
OUTPUT = cross

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(GCC) $(INCLUDES) $(OBJECTS) -o $(OUTPUT)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm $(OBJECTS) $(OUTPUT)

re:
	make clean
	make all
