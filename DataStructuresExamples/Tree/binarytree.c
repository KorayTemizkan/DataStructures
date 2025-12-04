#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

Node *pRoot = NULL;
Node *createNode(int value)
{
    Node *pNewNode = (Node *)malloc(sizeof(Node));
    pNewNode->data = value;
    pNewNode->pRight = NULL;
    pNewNode->pRight = NULL;
    return pNewNode;
}

Node *insertNode(Node *pRoot, int value)
{
    if (pRoot == NULL)
    {
        return createNode(value);
    }

    if (value < pRoot->data)
    {
        pRoot->pLeft = insertNode(pRoot->pLeft, value);
    }

    else if (value > pRoot->data)
    {
        pRoot->pRight = insertNode(pRoot->pRight, value);
    }

    else if (value == pRoot->data)
    {
        return pRoot;
    }
}

Node *searchNode(Node *pRoot, int value)
{
    if (pRoot == NULL)
    {
        return NULL;
    }

    else if (value < pRoot->data)
    {
        return searchNode(pRoot->pLeft, value);
    }

    else if (value > pRoot->data)
    {
        return searchNode(pRoot->pLeft, value);
    }

    else if (value == pRoot->data)
    {
        return pRoot;
    }
}

Node *deleteNode(Node *pRoot, int value)
{
    if (pRoot == NULL)
    {
        return NULL;
    }

    else if (value < pRoot->data)
    {
        return pRoot->pLeft = deleteNode(pRoot, value);
    }

    else if (value > pRoot->data)
    {
        return pRoot->pRight = deleteNode(pRoot, value);
    }

    else if (value == pRoot->data)
    {
        if (pRoot->pLeft == NULL)
        {
            Node *pRightTemporary = pRoot->pRight;
            free(pRoot);
            return pRightTemporary;
        }

        else if (pRoot->pRight == NULL)
        {
            Node *pLeftTemporary = pRoot->pLeft;
            free(pRoot);
            return pLeftTemporary;
        }

        else if (pRoot->pLeft != NULL && pRoot->pRight != NULL)
        {
            Node
        }
    }
}

int main()
{

    return 0;
}