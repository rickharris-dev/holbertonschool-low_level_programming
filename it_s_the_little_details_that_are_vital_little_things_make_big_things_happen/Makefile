DIR := src
INC := -Iinc
CFLAGS := -Wall -pedantic -Werror -Wextra
FILES := absolute.c cap_string.c contact_strings.c first_digit.c is_prime_number.c lowercase.c nconcat_strings.c positive_or_not.c power.c print_array.c print_char.c print_number.c print_string.c reverse_array.c reverse_string.c square_root.c string_copy.c string_ncopy.c strings_compare.c string_to_integer.c str_len.c swap_int.c uppercase.c uppercase_string.c
SOURCES := $(foreach file,$(FILES),$(patsubst %,$(DIR)/%,$(file)))
OBJECTS := $(SOURCES:%.c=%.o)

$(DIR)/%.o: $(DIR)/%.c
	gcc -c $(INC) -o $@ $< $(CFLAGS)

all: libholberton.a

libholberton.a: $(OBJECTS)
	ar -rc libholberton.a $(OBJECTS)

clean:
	rm $(OBJECTS) libholberton.a

re: $(OBJECTS)
