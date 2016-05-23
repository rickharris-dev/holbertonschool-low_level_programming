
CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra
INCLUDES = hdr.h libshell.h structs.h
SOURCES = chdir.c chkbuiltins.c chkpath.c env.c execcmd.c exit.c intfunc.c \
		listfunc.c memfunc.c prntfunc.c shell.c specchar.c \
		strfunc.c vars.c
LIBRARY = libshell.a
OBJECTS = $(SOURCES:.c=.o)
OUTPUT = shell

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) $(LIBRARY) -o $(OUTPUT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS) $(OUTPUT)

re:
	rm $(OBJECTS) $(OUTPUT)
	$(MAKE)
