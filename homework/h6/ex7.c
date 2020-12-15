#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "linked_list.h"
// int ex7() {
//     node_t *a=Initialize('1');
//     node_t *b=NULL;
//     PrintList(a);
//     InsertFirstList(&a, 'V');
//     InsertFirstList(&a, 'M');
//     PrintList(a);
//     InsertLastList(&a, 'C');
//     PrintList(a);
//     SplitList(&a, &b, 2);
//     PrintList(a);
//     PrintList(b);
//     DeleteFirstList(&a);
//     PrintList(a);
//     InsertLastList(&a, 'G');
//     DeleteLastList(&b);
//     PrintList(b);
//     InsertLastList(&b,'0');
//     PrintList(b);
//     InsertLastList(&b, '1');
//     PrintList(b);
//     MergeList(&a,&b);
//     PrintList(a);
//     char target='G';
//     printf("Count '%c': %d\n",target, SearchList(&a,target));
//     target='1';
//     printf("Count '%c': %d\n",target, SearchList(&a,target));
//     FreeList(&a);
// return 0;
// }


node_t *Initialize(char ch)
{
    node_t *head;
    head = (node_t *)calloc(1,sizeof(node_t)); //init pointer->head
    if (head == NULL)
    {
        fprintf(stderr,"Failed to assign memory!\n");
        exit(-1);
    }
    head->next = NULL; //empty pointer
    head->ch = ch;     //list 1.ch= '1'
    return head;       //list 1 = head
}

void PrintList(node_t *head)
{
    node_t *temp = head;
    printf("***Print Linked List***\n");
    while (temp != NULL)
    {
        printf("%c ",temp->ch);
        temp = temp->next;
    }
    printf("\n****Print Finished****\n\n");
}

void FreeList(node_t **head)
{
    node_t *tmp = NULL;
    node_t *pHead = *head;
    while (pHead->next != NULL)
    {
        tmp = pHead;
        pHead = pHead->next;
        free(tmp);
    }
    free(pHead);
}

// coding part

bool IsEmptyList(node_t *head)
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InsertFirstList(node_t **head,char insert_char)
{ // Prepend a node
    if (*head == NULL)
    {
        *head = Initialize(insert_char);
    }
    else
    {
        node_t *temp;
        temp = (node_t *)calloc(1,sizeof(node_t));
        temp->ch = insert_char;
        temp->next = *head;
        *head = temp;
    }
}

void InsertLastList(node_t **head,char insert_char)
{ // Append a node
    if (*head == NULL)
    {
        *head = Initialize(insert_char);
    }
    else
    {
        node_t *last;
        last = *head;
        node_t *ptr;
        ptr = (node_t *)calloc(1,sizeof(node_t));
        ptr->ch = insert_char;
        ptr->next = NULL;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = ptr;
        return;

    }
}

void DeleteFirstList(node_t **head)
{ // Delete the first element in the list
    if (*head != NULL)
    {
        node_t *temp;
        temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }
}

void DeleteLastList(node_t **head)
{ // Delete the last element in the list
    node_t *last;
    last = *head;
    if (last != NULL)
    {
        node_t *temp = *head;
        while (last->next != NULL)
        {
            temp = last;
            last = last->next;
        }
        if (temp == last)
        {
            free(temp);
            *head = NULL;
            return;
        }
        else
        {
            temp->next = NULL;
            free(last);
            return;
        }

    }
    else
        return;
}

int SizeList(node_t *head)
{ //correct?
    node_t *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

int SearchList(node_t **head,char target)
{ // Count how many times target appears
    node_t *ptr = *head;
    int i = 0;
    while (ptr != NULL)
    {
        if (ptr->ch == target)
        {
            i++;
        }
        ptr = ptr->next;
    }
    return i;
}

void SplitList(node_t **head,node_t **tail,int pos)
{ // Split into [0;pos-1] and [pos,end]
    node_t *ptr1 = *head;
    if (IsEmptyList(*head) == false)
    {
        if (pos > SizeList(*head))
        {
            *tail = NULL;
            return;
        }
        else if (pos <= 0)
        {
            *tail = *head;
            *head = NULL;
        }

        for (int i = 0;i < (pos - 1);i++,ptr1 = ptr1->next);
        *tail = ptr1->next;
        ptr1->next = NULL;
        /*
        if (SizeList(*head) >= 2)
        {
            for (int i = 0; i < (pos - 1); i++)
            {
                ptr1 = ptr1->next;
            }
            *tail = ptr1->next;
            ptr1->next = NULL;
        }
        else
        {
            *tail = ptr1;
            *head = NULL;
        }
        */
    }
}

void MergeList(node_t **head1,node_t **head2)
{
    if (*head1 != NULL || *head2 != NULL)
    {
        if (*head1 == NULL)
        {
            *head1 = *head2;
            *head2 = NULL;
        }
        else
        {
            node_t *smartass = *head1;
            for (;smartass->next != NULL;smartass = smartass->next);
            smartass->next = *head2;
            *head2 = NULL;
        }
        /*
        if (IsEmptyList(*head2) == true)
        {
            return;
        }
        node_t *ptr = *head1;
        if (IsEmptyList(*head1) == false)
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
            }
            ptr = *head2;
        }
        else
        {
            *head1 = *head2;
        }
        */
    }
}
