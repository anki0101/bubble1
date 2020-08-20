#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
}*start;

void create_list(int);
void addatbeg(int);
void addafter(int,int);
void delete(int);
void display();
int main()
{
    int choice;
    int ele;
    int number;
    int i;
    int pos;

    start = NULL;
    while(1)
    {

        printf("1. Create List\n");
        printf("2. Add at Beg\n");
        printf("3. Add after\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Please enter your choice: \n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: 
            printf("Enter element add in list: \n");
            scanf("%d",&number);
            create_list(number);
            break;

            case 2:
            printf("Enter element add in list: \n");
            scanf("%d",&number);
            addatbeg(number);
            break;

            case 4:
            printf("\nEnter number to delete: ");
            scanf("%d", &number);
            delete(number);
            break;

            case 5:
            display();
            break;
            case 6:
            break;

        default:
            break;
        }
    }
}
void create_list(int ele)
{
    struct node *ptr,  *temp = start;

    ptr = malloc(sizeof(struct node));
    ptr->data = ele;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (start == NULL)
    {
        start = ptr;
    } 
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        ptr->prev = temp;
        temp->next = ptr;
    }
    printf("Number entered\n");
}

void addatbeg(int ele)
{
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = ele;
    ptr->next = start;
    if(start != NULL)
        start -> prev = NULL;
    start = ptr;
}

void delete(int ele)
{
    struct node *temp = start;

    while (temp != NULL)
    {
        if (temp->data == ele)
        {
            if (temp == start)
            {
                start = start->next;
                start->prev = NULL;
            } 
            else
            {
                if (temp->next == NULL)
                    temp->prev->next = NULL;
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                free(temp);
            }
            printf("Number was deleted! Thanks \n");
            return ; 
        }
        temp = temp->next; 
        
    }
    printf("\n%d not found.", ele);
}

void display()
{
	struct node *temp = start;
    printf("\n");

    /* traverse the entire linked list */
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } 
    printf("\n");
}