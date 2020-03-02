#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef enum
{
    UNKNOWN,
    STRING,
    INTEGER
} type;

char *type_str[] = {"unknown", "string", "integer"};

typedef struct
{
    int argc;
    void **argv;
    // Here argv is the pointer to pointer which is (char *) or the one to int.
    type *types;
} t_obj;

void show_info(t_obj *obj)
{
    printf("-------------------------------------------\n");
    printf("argc=%d\n", obj->argc);
    for (int i = 0; i < obj->argc; i++)
    {
        type t = (type) * (obj->types + i);
        void **argv = (void **)(obj->argv + i);
        switch (t)
        {
        case UNKNOWN:
            printf("  No a resolved data|\n");
            break;
        case INTEGER:
            printf("  Type=%8s, Data=%8d\n", type_str[t], *(int *)(*argv));
            break;
        case STRING:
            printf("  Type=%8s, Data=%8s\n", type_str[t], (char *)argv);
            break;
        }
    }
}

/*
    A easy version of printf in stdio library.
    According to format to create t_obj object with corresponding element value.
 */
t_obj *create_obj(char *format, ...)
{
    size_t forward_length = strlen(format);
    va_list ap;
    va_start(ap, forward_length);
    va_end(ap);

    t_obj *t_ptr = (t_obj *)malloc(sizeof(t_obj));
    t_ptr->argc = forward_length;
    t_ptr->argv = (void **)malloc(sizeof(void **) * forward_length);
    t_ptr->types = (type *)malloc(sizeof(type *) * forward_length);
    void **argv = t_ptr->argv;

    for (int i = 0; i < forward_length; i++)
    {
        char current_format = *(format + i);
        switch (current_format)
        {
        case 'd':
            *(t_ptr->types + i) = INTEGER;
            int *int_ptr = malloc(sizeof(int *));
            *int_ptr = va_arg(ap, int);
            *(argv + i) = int_ptr;
            break;
        case 's':
            *(t_ptr->types + i) = STRING;
            strcpy((char *)(t_ptr->argv + i), va_arg(ap, char *));
            break;
        default:
            *(t_ptr->types + i) = UNKNOWN;
            *(t_ptr->argv + i) = NULL;
            break;
        }
    }
    return t_ptr;
}

void clear_obj(t_obj *obj)
{
    free(obj->argv);
    free(obj->types);
    free(obj);
}

int main(int argc, char *argv[])
{
    t_obj *ptr = create_obj("dsdsds", 1, "abc", 2, "efg", 3, "hij");
    show_info(ptr);
    clear_obj(ptr);
    return EXIT_SUCCESS;
}