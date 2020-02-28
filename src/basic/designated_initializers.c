/*
    Designated initialzer is c language feature since c99 standard.
    And most specail things is this feature is only for c not for C++
    It supported for aggregate types, including arrays, structures, and unions.
*/
#include <stdlib.h>
#include <stdio.h>

/* 
Demonstration for designated initializer with array:
return a array = {0,1,2,3}
*/
int *desi_0123()
{
    static int r[4] = {[3] = 3, [2] = 1, [1] = 1};
    return r;
}

typedef struct
{
    int ele;
} exam_strct;

/* 
Demonstration for designated initializer with struct:
return a struct: {.ele=0}
*/
exam_strct desi_strct()
{
    static exam_strct r = {.ele = 1};
    return r;
}

typedef union {
    int ele;
} exam_union;

/* 
Demonstration for designated initializer with union:
return a struct: {.ele=0}
*/
exam_union desi_union()
{
    static exam_union r = {.ele = 1};
    return r;
}

int main(int argc, char *argv[])
{

    // Get a hardcode array created by designated initializer
    int *a = desi_0123();
    // It is impossible to get the length of the array by a pointer to it in runtime.
    // But this hardcode array I have the correct array size!
    for (int i = 0; i < 4; i++)
    {
        printf("Array element:%d, value=%d\n", i, *a);
        a++;
    }

    // A struct object generated by designated initializer, whose ele = 1;
    printf("strct ele=%d\n", desi_strct().ele);
    // A struct object generated by designated initializer, whose ele = 1;
    printf("union ele=%d\n", desi_union().ele);

    return EXIT_SUCCESS;
}
