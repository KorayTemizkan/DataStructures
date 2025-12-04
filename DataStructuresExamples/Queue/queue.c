// push, pop, top(tepedekini göstermek), isempty, length, isthere, clear, print

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

typedef struct Node Node;
struct Node
{
    char name[21];
    char surname[21];
    Node *pNext;
};

Node *pFront = NULL;
Node *pBack = NULL;

void enqueue(char *fname, char *fsurname)
{
    Node *pNewNode = (Node *)malloc(sizeof(Node));

    memset(pNewNode, 0, sizeof(Node));
    strncpy(pNewNode->name, fname, 20);
    strncpy(pNewNode->surname, fsurname, 20);
    pNewNode->pNext = NULL;

    if (pFront == NULL)
    {
        pFront = pNewNode;
        pBack = pNewNode;
        return;
    }

    pBack->pNext = pNewNode;
    pBack = pNewNode;
}

void dequeue()
{
    Node *pTemporary = pFront;
    pFront = pFront->pNext;
    free(pTemporary);
}

void top()
{
    printf("%s %s", pFront->name, pFront->surname);
}

void isEmpty()
{
    if (pFront != NULL)
    {
        printf("%s", "Liste bos");
    }
    else
    {
        printf("%s", "Liste dolu");
    }
}

int main()
{

    return 0;
}