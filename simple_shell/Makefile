
CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra
INCLUDES = my_header.h libshell.h
SOURCES = check_builtins.c check_path.c env.c exec_program.c exit.c \
		mem_func.c simple_shell.c string_functions.c vars.c \
		write_functions.c
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
