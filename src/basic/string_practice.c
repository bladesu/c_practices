#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void show_size(char test[])
{
    printf("%lu\n", sizeof(test));
}
int main(void)
{
    /* __c_code1__: show address with operator act upon char array. */
    printf("1)----------------------------------------------------\n");
    printf("Value of a char array object is just its address.\n");
    char c_arr[] = "abc";
    printf("(value vs address) = (%p vs %p)\n", c_arr, &c_arr);
    printf("Is they identical?:%s\n", (void *)c_arr == (void *)&c_arr ? "Yes" : "No");

    /* __c_code2__: show size and contents in declared char array without assigning values. */
    printf("2)----------------------------------------------------\n");
    printf("Initailization of char array without given specific char values\n");
    char no_init[2];
    printf("sizeof(\"%s\")=%lu\n", "no_init", sizeof(no_init));
    printf("First char in \"%s\":'%c'\n", "no_init", *no_init);
    printf("Is first char equal to NUL terminator(\'\\0\')?:%s\n", *no_init == '\0' ? "Yes" : "No");
    printf("Is second char equal to NUL terminator(\'\\0\')?:%s\n", *(no_init + 1) == '\0' ? "Yes" : "No");

    /* __c_code3__: show same operator to retrive memory address: */
    printf("3)----------------------------------------------------\n");
    printf("String literals and char array\n");
    char c_arr_op[] = "abc";
    printf("Address Representation1: with address operator\n");
    printf("    Address of string literal \"abc\":%p\n", &"abc");
    printf("    Address of c_arr_op:%p\n", &c_arr_op);

    printf("Address Representation2: without address operator\n");
    printf("    Address of string literal \"abc\":%p\n", "abc");
    printf("    Address of c_arr_op:%p\n", c_arr_op);

    /* __c_code4__: show the reusable properties of __string literal__ by assigned same __string literal__ to different char pointer. */
    printf("4)----------------------------------------------------\n");
    printf("Reusable of string literal object\n");
    char *c_arr_op1 = "abc";
    char *c_arr_op2 = "abc";
    printf("%s points to address=%p\n", "c_arr_op1", c_arr_op1);
    printf("%s points to address=%p\n", "c_arr_op2", c_arr_op2);
    printf("String literal \"%s\" has address=%p\n", "abc", &"abc");

    printf("5)----------------------------------------------------\n");
    char c_arr1[] = "abc";
    printf("Find value and memory address in char array and string literal as target to copied.\n");
    for (int i = 0; i < sizeof(c_arr1); i++)
    {
        printf("Serial order:%d\n", i);
        printf("    In \"%s\": value=%c, address=%p\n", "abc", (char)*((char *)&"abc" + i), &"abc" + i);
        printf("    In \"%s\": value=%c, address=%p\n", "c_arr1", (char)*((char *)c_arr1 + i), c_arr1 + i);
    }

    /* __c_code6__: show address of a __pointer to char__ and its value: */
    printf("6)----------------------------------------------------\n");
    char foo = 'a';
    char *char_ptr;
    char_ptr = &foo;
    printf("|%10s|%18s|%15s|\n", "object", "address", "value(hex|char");
    printf("|%10s|%18p|%15c|\n", "foo", &foo, foo);
    printf("|%10s|%18p|%15p|\n", "char_ptr", &char_ptr, char_ptr);

    /* __c_code7__: show sizes of __string literal__ and __pointer to char__.*/
    printf("7)----------------------------------------------------\n");
    char foo1[] = "abc";
    char foo2[] = {'a', 'b', 'c'};
    char *foo3 = "abc";

    printf("sizeof \"%s\" = %lu\n", "abc", sizeof("abc"));
    printf("sizeof %s = %lu\n", "foo1", sizeof(foo1));
    printf("sizeof %s = %lu\n\n", "foo2", sizeof(foo2));

    printf("sizeof %s = %lu\n", "（void*)", sizeof(void *));
    printf("sizeof %s = %lu\n", "foo3", sizeof(foo3));

    /* __c_code8__ : try char array as argument to a function. */
    printf("8)----------------------------------------------------\n");
    char test[] = "123";
    printf("sizeof a string literal:%lu\n", sizeof("123"));
    printf("sizeof a char array:%lu\n", sizeof(test));
    printf("sizeof a (char *):%lu\n", sizeof(char *));
    show_size("123");
    show_size(test);

    /* __c_code9__: try printf in stdio.h */
    printf("9)----------------------------------------------------\n");
    char abc1[] = {'a', 'b', 'c'};
    char abc2[] = {'a', 'b', '\0', 'c'};
    printf("%s\n", abc1);
    printf("%s\n", abc2);
    printf("%s\n", "abc\0efg");

    /* __c_code10__: try strcpy in string.h */
    printf("10)----------------------------------------------------\n");
    char *char_p1;
    strcpy(char_p1, "abc\0def");
    printf("%s\n", char_p1);

    /* __c_code11__: wrong use case in strcpy in string.h */
    printf("11)----------------------------------------------------\n");
    char *str_literal_1 = "abc";
    char *char_arr_test = "def";
    //Segmentation fault
    strcpy(str_literal_1, char_arr_test);
    return 0;
}