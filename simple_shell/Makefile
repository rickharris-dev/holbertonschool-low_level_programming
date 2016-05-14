
CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra
INCLUDES = my_header.h libshell.h
SOURCES = write_functions.c simple_shell.c exec_program.c string_functions.c
LIBRARY = libshell.a
OBJECTS = $(SOURCES:.c=.o)
OUTPUT = simple_shell

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(GCC) $(INCLUDES) $(OBJECTS) $(LIBRARY) -o $(OUTPUT)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm $(OBJECTS) $(OUTPUT)

re:
	rm $(OBJECTS) $(OUTPUT)
	$(MAKE)
