#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*start,*end;

void create_list(int);
void addatbeg(int);
void addafter(int,int);
void delete(int);
void display();

int main()
{
    int choice;
    int ele;
    int nSize;
    int i;
    int pos;
    printf("***********************WELCOME TO CIRCULAR DOUBLY LINKED LIST***********************\n\n");

    start = NULL;
    while(1)
    {
        printf("1. Create List\n");
        printf("2. Add at Beg\n");
        printf("3. Add after\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the number of list you want print : \n");
            scanf("%d",&nSize);
            for ( i = 0; i < nSize; i++)
            {
                printf("Enter the element in the CIRCULAR Linked List %d: ",i);
                scanf("%d",&ele);
                create_list(ele);
            }
            break;

            case 2: 
            printf("Enter element in the CIRCULAR Linked list\n");
            scanf("%d",&ele);
            addatbeg(ele);
            break;

            case 5:
            display();
            break;

            case 6:
            break;
        }
        
    }
}

void create_list(int ele)
{
    struct node *newnode;
    start=0;
    newnode = (struct node*) malloc(sizeof(struct node));
    ele = newnode->data;
    if(start == 0)
    {
        start = end = newnode;
        start -> next = start;
        start -> prev = start;
    }
    else
    {
        end -> next = newnode;
        newnode -> prev = end;
        newnode -> next = start;
        start -> prev = newnode;
        end = newnode;
    }

}

void display()
{
    struct node *temp;
    temp = start;
    if (start == 0)
    {
        printf("OOOfffsssss!!!!!!!!!! Please try Once Again\n");
    }
    else
    {
        while (temp!= 0)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
        printf("\n");
    }
   
}

void addatbeg(int ele)
{
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    ele = newnode->data;
    if(start == 0)
    {
        start = end =newnode;
        newnode -> prev = end;
        newnode -> next = start;
    }
    else
    {
        newnode -> next = start;
        start   -> prev = newnode;
        newnode -> prev = end;
        end     -> next = newnode;
        start = newnode;
    }
}