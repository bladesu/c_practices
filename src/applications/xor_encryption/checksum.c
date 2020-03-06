#include "checksum.h"

int checksum(encrypt_data *e_data)
{
    int *data = e_data->data;
    size_t limit = e_data->length;
    int c = 0;
    while (limit > 0)
    {
        c += (int)(*data);
        data++;
        limit--;
    }
    return c;
}