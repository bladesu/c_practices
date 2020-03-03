#include <stdlib.h>
#include <stdio.h>

/*
    According to bit_size, print bit value for obj.
*/
void print_bit(void *const obj, unsigned long const bit_size)
{
    // For bitwise AND operator,
    // The each of operands shall have integer type according to C99 standard (6.5.10) 
    unsigned int *x = obj;
    unsigned long leftest = 8 * bit_size;
    while (leftest > 0)
    {
        leftest--;
        (*x & (1 << leftest)) ? putchar('1') : putchar('0');
        if (!(leftest % 8))
            putchar(' ');
    }
    putchar('\n');
}

int main(void)
{
    printf("Starting...\n");

    int int_obj = 1;
    printf("for int :%d\n", int_obj);
    print_bit(&int_obj, sizeof(int_obj));

    char char_obj = 'a';
    printf("for char :%c\n", char_obj);
    print_bit(&char_obj, sizeof(char_obj));

    float float_obj = -2.25;
    printf("for float :%f \n", float_obj);
    print_bit(&float_obj, sizeof(float_obj));

    /*
      Show effect of bitwise exclusive OR opeator.
      The each of operands shall have integer type according to C99 standard (6.5.11)  
    */
    unsigned int xor_int1 = 20;
    unsigned int xor_int2 = 21;
    printf("check what happend to (int) XOR (int): %d ^ %d\n", xor_int1, xor_int2);
    printf("sizeof int = %lu\n", sizeof(unsigned int));

    printf("binary for %8d=", xor_int1);
    print_bit(&xor_int1, sizeof(unsigned int));

    printf("binary for %8d=", xor_int2);
    print_bit(&xor_int2, sizeof(unsigned int));


    unsigned int xor_result = xor_int1 ^ xor_int2;
    printf("xor result         =");
    print_bit(&(xor_result), sizeof(unsigned int));

    printf("End...\n");

    return 0;
}
