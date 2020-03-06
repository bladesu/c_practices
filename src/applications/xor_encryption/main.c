#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "checksum.h"
#include "encrypt.h"

int main(int argc, char *argv[])
{
    char s[] = "1234";
    int xor_seed = 79979;
    encrypt_data *edata = create_edata((int *)s, sizeof(s));
    printf("Original  :%d\n", checksum(edata));
    encrypt_xor(edata, xor_seed);
    printf("Encrypted :%d\n", checksum(edata));
    encrypt_xor(edata, xor_seed);
    printf("Decrypted :%d\n", checksum(edata));
    destory_edata(edata);

    return EXIT_SUCCESS;
}