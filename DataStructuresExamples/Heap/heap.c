#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct HeapTree HeapTree;
struct HeapTree
{
    int array[MAX_SIZE];
    int size;
};
HeapTree heapTree = {.size = 0};

int bringLeftChild(int index)
{
    return 2 * index + 1;
}

int bringRightChild(int index)
{
    return 2 * index + 2;
}

int bringParent(int index)
{
    return (index - 1) / 2;
}

void insert(int value)
{
    if (heapTree.size == MAX_SIZE)
    {
        return;
    }

    heapTree.array[heapTree.size] = value;
    heapTree.size++;

    HeapifyUp(heapTree.size-1);
}

void HeapifyUp(int index) {
    if (index == 0)
    {
        return;
    }

    int parentIndex = bringParent(index);

    if (heapTree.array[parentIndex] > heapTree.array[index])
    {
        int temp = heapTree.array[index];
        heapTree.array[index] = heapTree.array[parentIndex];
        heapTree.array[parentIndex] = temp;

        HeapifyUp(parentIndex);
    }
}

void delete() { // kök silinir
    if (heapTree.size == 0)
    {
        return;
    }

    heapTree.array[0] = heapTree.array[heapTree.size-1];
    heapTree.size--;

    heapifyDown(0);
}

void heapifyDown(int index) {
    int leftChildIndex = bringLeftChild(index);
    int rightChildIndex = bringRightChild(index);
    int minIndex;
    if (rightChildIndex >= heapTree.size)
    {
        if (leftChildIndex >= heapTree.size)
        {
            return;
        }
        
        else
        {
            minIndex = leftChildIndex;
        }
    }

    else
    {
        if (heapTree.array[leftChildIndex] < heapTree.array[rightChildIndex])
        {
            minIndex = leftChildIndex;
        }
        
        else
        {
            minIndex = rightChildIndex;
        }
    }

    if (heapTree.array[minIndex] < heapTree.array[index])
    {
        int temp = heapTree.array[index];
        heapTree.array[index] = heapTree.array[minIndex];
        heapTree.array[minIndex] = temp;

        heapifyDown(minIndex);
    }
}

int main()
{

    return 0;
}