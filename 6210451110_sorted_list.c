//6210451110 Chanon Limvongrujirat
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void sort(Node **first)
{
    int i, j, z;
    Node *tmp1, *tmp2;
    for (tmp1 = *first; tmp1 != NULL; tmp1 = tmp1->next)
    {
        for (tmp2 = tmp1->next; tmp2 != NULL; tmp2 = tmp2->next)
        {
            if (tmp2->data < tmp1->data)
            {
                z = tmp1->data;
                tmp1->data = tmp2->data;
                tmp2->data = z;
            }
        }
    }
}

void listtttt(Node **first, Node **new)
{
    int input;

    while (scanf("%d", &input) == 1)
    {
        if (input <= -1)
            break;
        else if (*first == NULL)
        {
            *first = *new = (Node *)malloc(sizeof(Node));
        }
        else
        {
            (*new)->next = (Node *)malloc(sizeof(Node));
            *new = (*new)->next;
        }
        (*new)->data = input;
        (*new)->next = NULL;
        sort(first);
    }
}

void printlist(Node *head)
{
    Node *tmp2 = head;
    for (tmp2 = head; tmp2; tmp2 = tmp2->next)
        printf("%d\n", tmp2->data);
}

int main()
{
    Node *first = NULL, *new;
    listtttt(&first, &new);
    printlist(first);
}