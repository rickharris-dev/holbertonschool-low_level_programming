CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra
INCLUDES = my_header.h
SOURCES = 0-print_content.c print_file.c
OBJECTS = $(SOURCES:.c=.o)
OUTPUT = 0-print_content

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(GCC) $(INCLUDES) $(OBJECTS) -o $(OUTPUT)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	rm $(OBJECTS) $(OUTPUT)

re:
	rm $(OBJECTS) $(OUTPUT)
	$(MAKE)
