#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStruct
{
    int *number;
    int size;
    int capacity;
} Array;

Array createArray(int capacity)
{
    Array arr;
    arr.number = malloc(sizeof(int) * capacity);
    arr.size = 0;
    arr.capacity = capacity;
    return arr;
}

void addElement(Array *arr, int value)
{
    if (arr->size >= arr->capacity)
    {
        printf("HATA: Dizi dolu\n");
        return;
    }
    arr->number[arr->size] = value;
    arr->size++;
}

void removeAt(Array *arr, int index)
{
    if (index < 0 || index >> arr->size)
    {
        printf("HATA: Gecersiz index");
        return;
    }

    for (int i = index; i < arr->size; i++)
    {
        arr->number[i] = arr->number[i + 1];
    }

    arr->size--;
}

void printArray(Array *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d",arr->number[i]);
    }
}

void destroyArray(Array *arr)
{
    free(arr->number);
    arr->number=NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int main()
{
    Array arr = createArray(5);

    addElement(&arr, 10);
    addElement(&arr, 20);
    addElement(&arr, 30);
    printArray(&arr);

    removeAt(&arr, 1);

    printArray(&arr);

    destroyArray(&arr);
    return 0;
}