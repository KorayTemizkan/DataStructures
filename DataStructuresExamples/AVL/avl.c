// AVL (Adelson-Velskii ve Landis)'ten adı geliyor.

#include <stdlib.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

Node *pRoot = NULL;

/*
      9
    8   10
  6
4

    9
  6   10
4   8
*/

// Bozulmanın olduğu düğüm üzerinden yapılır.
Node *turnRight(Node *pParent)
{
    Node *pLeftChild = pParent->pLeft;
    pParent->pLeft = pLeftChild->pRight;
    pLeftChild->pRight = pParent;
    return pLeftChild;
}

Node *turnLeft(Node *pParent)
{
    Node *pRightChild = pParent->pRight;
    pParent->pRight = pRightChild->pLeft;
    pRightChild->pLeft = pParent;
    return pRightChild;
}

Node *createNode(int value)
{
    Node *pNewNode = (Node *)malloc(sizeof(Node));
    pNewNode->data = value;
    pNewNode->pRight = NULL;
    pNewNode->pRight = NULL;
    return pNewNode;
}

int height(Node *pRoot)
{
    if (pRoot == NULL)
    {
        return 0;
    }

    int hleft = height(pRoot->pLeft);
    int hright = height(pRoot->pRight);

    if (hleft > hright)
    {
        return hleft + 1;
    }

    else
    {
        return hright + 1;
    }
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

        if (height(pRoot->pLeft) - height(pRoot->pRight) > 1)
        {
            if (value < pRoot->pLeft->data)
            {
                pRoot = turnRight(pRoot);
            }

            else if (value > pRoot->pLeft->data)
            {
                pRoot->pLeft = turnLeft(pRoot->pLeft);
                pRoot = turnRight(pRoot); // sol sol dengesizliği
            }
        }
    }

    else if (value > pRoot->data)
    {
        pRoot->pRight = insertNode(pRoot->pRight, value);

        if (height(pRoot->pRight) - height(pRoot->pLeft) > 1)
        {
            if (value > pRoot->pRight->data)
            {
                pRoot = turnLeft(pRoot);
            }

            else
            {
                pRoot->pRight = turnRight(pRoot->pRight);
                pRoot = turnLeft(pRoot);
            }
        }
    }

    else if (value == pRoot->data)
    {
        return pRoot;
    }

    return pRoot;
}