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

Node *findMin(Node *pRoot)
{
    Node *pFindMin = pRoot;

    while(pFindMin->pLeft != NULL) {
        pFindMin = pFindMin->pLeft;
    }
    
    return pFindMin;
}

Node *deleteNode(Node *pRoot, int value)
{
    if (pRoot == NULL)
    {
        return NULL;
    }

    else if (value < pRoot->data) // sol taraf
    {
        return pRoot->pLeft = deleteNode(pRoot->pLeft, value);
    }

    else if (value > pRoot->data) // sağ tarafı
    {
        return pRoot->pRight = deleteNode(pRoot->pRight, value);
    }

    else if (value == pRoot->data)
    {
        if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
        {
            free(pRoot);
            return NULL;
        }

        else if (pRoot->pLeft == NULL)
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
            Node *pMinRight = findMin(pRoot->pRight);
            pRoot->data = pMinRight;
            pMinRight->pRight = deleteNode(pRoot->pRight, pMinRight->data);
            return pRoot;
        }
    }
}

void preorder(Node *pRoot) {
    if (pRoot == NULL)
    {
        return;
    }
    printf("%d ", pRoot->data);
    preorder(pRoot->pLeft);
    preorder(pRoot->pRight);
}

void inorder(Node *pRoot) {
    if (pRoot == NULL)
    {
        return;
    }
    inorder(pRoot->pLeft);
    printf("%d ",pRoot->data);
    inorder(pRoot->pRight);    
}

void postorder(Node *pRoot) {
    if (pRoot == NULL)
    {
        return;
    }
    postorder(pRoot->pLeft);
    postorder(pRoot->pRight);
    printf("%d ",pRoot->data);
}

void destroyTree() {
    if (pRoot == NULL)
    {
        return;
    }

    postorder(pRoot->pLeft);
    postorder(pRoot->pRight);
    free(pRoot);
}

int main()
{

    return 0;
}