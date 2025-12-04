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

Node *pHead = NULL;
Node *pTail = NULL;

// 1(HEAD) -> 2 -> 3 -> 4(TAİL)
void *addListNewItemToHead(char *fname, char *fsurname)
{
    Node *pNewNode = (Node *)malloc(sizeof(Node));

    if (pNewNode != NULL)
    {
        memset(pNewNode, 0, sizeof(Node)); // Biz yer ayırdık ama içindeki değerler rastgele, hepsini 0 bit yaparak temizliyoruz.
        strncpy(pNewNode->name, fname, 20);
        strncpy(pNewNode->surname, fsurname, 20);

        if (pHead == NULL)
        {
            pHead = pNewNode;
            pTail = pNewNode;
            return pHead;
        }

        pNewNode->pNext = pHead;
        pHead = pNewNode;
    }
} // DEMET -> KORAY

// 1(HEAD) -> 2 -> 3 -> 4(TAİL)
void *addListNewItemToTail(char *fname, char *fsurname)
{
    Node *pNewNode = (Node *)malloc(sizeof(Node));

    if (pNewNode != NULL)
    {
        memset(pNewNode, 0, sizeof(Node));
        strcpy(pNewNode->name, fname);
        strcpy(pNewNode->surname, fsurname);

        if (pTail == NULL)
        {
            pHead = pNewNode;
            pTail = pNewNode;
            return pNewNode;
        }

        pTail->pNext = pNewNode;
        pTail = pNewNode;
    }
}
//                    Sefter
// Koray(HEAD) -> Fidan -> Demet -> Nimet(TAİL)

void *addListNewItemToChoosenPlace(char *fname, char *fsurname, char *choosen)
{
    Node *pNewNode = (Node*)malloc(sizeof(Node));
    Node *pSelectedNode = pHead;

    if (pNewNode != NULL)
    {

        memset(pNewNode, 0, sizeof(Node));
        strcpy(pNewNode->name, fname);
        strcpy(pNewNode->surname, fsurname);

        while (pSelectedNode != NULL && strcmp(pSelectedNode->name, choosen)!=0)
        {
            pSelectedNode = pSelectedNode->pNext;
        }

        printf("%s",pSelectedNode->name);
        pNewNode->pNext = pSelectedNode->pNext;
        pSelectedNode->pNext=pNewNode;

    }

    return pNewNode;
}

// Fidan->Demet->Koray->Sahin->Bedirhan->Elmir
// addListNewItemToChoosenPlace("Emirhan","Uzun","Sahin");

int isThere(char *fname)
{
    Node *pSelected = pHead;

    while (pSelected != NULL)
    {
        if (strcmp(pSelected->name, fname) == 0)
        {
            return 1;
        }

        pSelected = pSelected->pNext;
    }

    return 0;
}

void clearList()
{
    Node *pSelected = pHead;
    while (pSelected != NULL)
    {
        pHead = pSelected->pNext;
        free(pSelected);
        pSelected = pHead;
    }
}

int length = 0;
void lengthOfList()
{
    length = 0;
    Node *pSelected = pHead;
    while (pSelected != NULL)
    {
        length++;
        pSelected = pSelected->pNext;
    }
    printf("Length: %d", length);
}

// FidanYusufZiyaDemetKorayOkanSahinEmirhanBedirhanElmir
void deleteChoosenItem(char *fname)
{ // 2'yi kaldırmaya çalışıyoruz
    Node *pSelected = pHead;

    while (pSelected != NULL && strcmp(pSelected->pNext->name, fname))
    {
        pSelected = pSelected->pNext;
    }

    pSelected->pNext=pSelected->pNext->pNext;
}

void printList()
{
    Node *pSelected = pHead;
    while (pSelected != NULL)
    {
        printf("%s", pSelected->name);
        pSelected = pSelected->pNext;
    }
}

int main()
{
    printf("CONTROL0");

    addListNewItemToHead("Koray", "Temizkan");
    addListNewItemToHead("Demet", "Temizkan");
    addListNewItemToHead("Fidan", "Abdullayeva");

    printf("CONTROL1");
    printList();
    lengthOfList();
    printf("\n\n");
    printf("CONTROL2");

    addListNewItemToTail("Sahin", "Bagci");
    addListNewItemToTail("Bedirhan", "Avsar");
    addListNewItemToTail("Elmir", "Gehramanov");

    printf("CONTROL3");

    if (isThere("Sahin"))
        printf("%s", "Listede bu kisi var");

    printf("\n\n");
    printList();
    printf("\n\n");
    printf("CONTROL4");

    // Fidan->Demet->Koray->Sahin->Bedirhan->Elmir
    addListNewItemToChoosenPlace("Emirhan", "Uzun", "Sahin");
    addListNewItemToChoosenPlace("Okan", "Koca", "Koray");
    addListNewItemToChoosenPlace("YusufZiya", "Gok", "Fidan");

    printf("\n\n");

    printList();

    printf("CONTROL5");

    lengthOfList();
    printf("\n\n");

    deleteChoosenItem("Okan");
    deleteChoosenItem("Sahin");
    deleteChoosenItem("Bedirhan");

    printf("CONTROL6");
    printList();
    lengthOfList();
    printf("\n\n");

    clearList();
    lengthOfList();
    printf("CONTROL7");

    printf("\n\n");

    return 0;
}