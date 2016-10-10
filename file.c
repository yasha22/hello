#include <stdio.h>
#include <stdlib.h>
#include "dyn_array.h"
#define ERR_REALLOCATION -1001



dyn_array *CreateArray(int size)
{
    dyn_array *new_dyn_array;
    new_dyn_array = (dyn_array *)malloc(sizeof(dyn_array));
    new_dyn_array -> V = (int *)malloc(size*sizeof(int));

    if(new_dyn_array->V == NULL)
    {
        printf("errore allocazione!");
        exit(-1000);
    }

    else
    {
        new_dyn_array -> dim=size;
        return new_dyn_array;
    }

}

void DeleteArray(dyn_array* arr)
{
    free(arr->V);
    free(arr);
}

void RedimArray(dyn_array* arr, int new_dim)
{
    arr->V = (int *)realloc(arr->V,new_dim);
    arr->dim = new_dim;

    if(arr->V == NULL)
        exit(ERR_REALLOCATION);

}

int IsValidIndex(dyn_array *arr, int index)
{
    if(index >= arr->dim )
        return 1;
    else
        return 0;
}

int ReadElement(dyn_array* arr, int index)
{
    return (int)((arr+index) -> V);
}

void WriteElement(dyn_array* arr, int index, int value)
{
    (arr+index) -> V =(int *) value;
}
