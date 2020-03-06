#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <stddef.h>

typedef struct _encrypt_data
{
    int *data;
    size_t length;
    size_t padding;
} encrypt_data;

extern void encrypt_xor(encrypt_data *const edata, int const seed);

extern encrypt_data *create_edata(void *data, size_t size);

extern void destory_edata(encrypt_data *edata);

#endif