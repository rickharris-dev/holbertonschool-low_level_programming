CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra
INCLUDES = my_header.h
SOURCES = 3-cat.c print_file_content.c print_file.c print_stdin.c
OBJECTS = $(SOURCES:.c=.o)
OUTPUT = 3-cat

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(GCC) $(INCLUDES) $(OBJECTS) -o $(OUTPUT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS) $(OUTPUT)

re:
	rm $(OBJECTS) $(OUTPUT)
	$(MAKE)
