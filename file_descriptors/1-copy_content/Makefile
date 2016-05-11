CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra
INCLUDES = my_header.h
SOURCES = 1-copy_content.c copy_file.c open_files.c close_files.c
OBJECTS = $(SOURCES:.c=.o)
OUTPUT = 1-copy_content

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
