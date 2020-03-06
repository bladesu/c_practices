#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "encrypt.h"

// according to c99, bitwise operation can apply to integer type.
void encrypt_xor(encrypt_data *const edata, int const seed)
{
    int *ptr = edata->data;
    size_t times = edata->length;
    size_t count = 0;
    while (count < times)
    {
        *ptr = *ptr ^ seed;
        ptr++;
        count++;
    }
    if (!(edata->padding))
    {

        int before_padding = sizeof(int) - edata->padding;
        int padding = sizeof(int) - before_padding;

        int word = 0;
        char *word_ptr_begin = (char *)&word;
        char *word_ptr = (char *)&word;
        char *ptrc = (char *)ptr;
        for (size_t i = 0; i < before_padding; i++)
        {
            *word_ptr = *ptrc;
            ptrc++;
            word_ptr++;
        }
        for (size_t i = 0; i < padding; i++)
        {
            *word_ptr = 'a'; // just put a easy char.
            word_ptr++;
        }
        int padding_word = *((int *)word_ptr_begin) ^ seed;
        //fill the padding
        char *pchar = (char *)&padding_word;
        ptrc = (char *)ptr;
        for (size_t i = 0; i < before_padding; i++)
        {
            *ptrc = *pchar;
            ptrc++;
            pchar++;
        }
    }
}

encrypt_data *create_edata(void *data, size_t size)
{
    encrypt_data *edata = (encrypt_data *)malloc(sizeof(encrypt_data));
    edata->data = data;
    edata->length = size / sizeof(int);
    edata->padding = size % sizeof(int);
    return edata;
}

void destory_edata(encrypt_data *edata)
{
    free(edata);
}