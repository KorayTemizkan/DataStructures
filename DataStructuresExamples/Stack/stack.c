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

Node *pTop = NULL;

void push(char *fname, char *fsurname)
{
    Node *pNewNode = (Node *)malloc(sizeof(Node));

    memset(pNewNode, 0, sizeof(Node));
    strncpy(pNewNode->name, fname, 20);
    strncpy(pNewNode->surname, fsurname, 20);
    pNewNode->pNext = NULL;

    if (pTop == NULL)
    {
        pTop = pNewNode;
        return;
    }

    pNewNode->pNext=pTop;
    pTop = pNewNode;
}

void pop()
{
    Node *pTemporary = pTop;
    pTop = pTop->pNext;
    free(pTemporary);
}

void top()
{
    printf("%s %s", pTop->name, pTop->surname);
}

void isEmpty()
{
    if (pTop != NULL)
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