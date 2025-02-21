#include <stdio.h>
#include <stdlib.h>

struct tnode 
{
    int x;
    struct tnode *next, *prev;
} *head, *tail;

void push_front(int value) 
{
    struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
    node->x = value;
    node->prev = NULL;
    node->next = head;
    
    if (head == NULL) 
	{
        head = tail = node;
    } 
	else 
	{
        head->prev = node;
        head = node;
    }
}

void push_back(int value) 
{
    struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
    node->x = value;
    node->next = NULL;
    
    if (head == NULL) 
	{
        head = tail = node;
        node->prev = NULL;
    } 
	else 
	{
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

void push_mid(int value, int searchKey) 
{
    if (head == NULL) 
	{
        printf("List is empty, adding to front.\n");
        push_front(value);
        return;
    }
    
    struct tnode *curr = head;
    while (curr != NULL) 
	{
        if (curr->x == searchKey) 
		{
            struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
            node->x = value;
            node->next = curr->next;
            node->prev = curr;
            
            if (curr->next != NULL) 
			{
                curr->next->prev = node;
            } else 
			{
                tail = node;
            }
            curr->next = node;
            return;
        }
        curr = curr->next;
    }
    printf("Data %d not found in the list\n", searchKey);
}

void delete_front() 
{
    if (head == NULL) 
	{
        printf("List is empty.\n");
        return;
    }
    struct tnode *del = head;
    head = head->next;
    if (head != NULL) 
	{
        head->prev = NULL;
    } 
	else 
	{
        tail = NULL;
    }
    free(del);
}

void delete_back() 
{
    if (tail == NULL) 
	{
        printf("List is empty.\n");
        return;
    }
    struct tnode *del = tail;
    tail = tail->prev;
    if (tail != NULL) 
	{
        tail->next = NULL;
    } 
	else 
	{
        head = NULL;
    }
    free(del);
}

void delete_mid(int value) 
{
    struct tnode *curr = head;
    while (curr != NULL) 
	{
        if (curr->x == value)
		{
            if (curr == head) 
			{
                delete_front();
                return;
            }
            if (curr == tail) 
			{
                delete_back();
                return;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
            return;
        }
        curr = curr->next;
    }
    printf("Data %d not found in the list\n", value);
}

void printList() 
{
    struct tnode *curr = head;
    if (curr == NULL) 
	{
        printf("List is empty\n");
        return;
    }
    while (curr != NULL) 
	{
        printf("%d ", curr->x);
        curr = curr->next;
    }
    printf("\n");
}

int main() 
{
    printf("Doubly Linked List\n");
    push_back(13);
    push_back(1);
    push_back(3);
    delete_front();
    push_back(99);
    push_mid(5, 1);
    printList();
    delete_back();
    printList();
    delete_mid(1);
    printList();
    return 0;
}

