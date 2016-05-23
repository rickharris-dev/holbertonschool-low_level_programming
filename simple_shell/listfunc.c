#include "hdr.h"

void free_strlist(struct Stringlist *list)
{
        struct Stringlist *next;

        if (list == NULL)
                return;

        next = list->next;
        free(list->str);
        free(list);

        free_strlist(next);
}

char ** list_to_strarr(struct Stringlist *list)
{
        int i;
        int len;
        char **array;

        len = strlist_len(list);
        array = malloc(sizeof(char *) * (len + 1));
        array[len] = NULL;
        for (i = 0; list != NULL; i++) {
                array[i] = list->str;
                list = list->next;
        }
        return array;
}

struct Stringlist *strarr_to_list(char **array)
{
        int i;
        struct Stringlist *first;
        struct Stringlist *new;
        struct Stringlist *prev;

        i = 0;
        while (array[i] != NULL) {
                new = malloc(sizeof(struct Stringlist));
                if (new == NULL) {
                        perror("malloc");
                        return NULL;
                }

                if (i == 0)
                        first = new;

                new->str = malloc_str(array[i]);
                if (new->str == NULL) {
                        perror("malloc");
                        return NULL;
                }
                if (i != 0) {
                        prev->next = new;
                }

                prev = new;
                i++;
        }

        prev->next = NULL;
        return first;
}

int strlist_len(struct Stringlist *list)
{
        int i;

        for (i = 0; list != NULL; i++) {
                list = list->next;
        }

        return i;
}
