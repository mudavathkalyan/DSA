// linear search...
#include<stdio.h>
#include<stdlib.h>
void create();
void traverse();
void search();
struct node
{
    int data;
    struct node *next;
}*head=NULL,*temp,*new,*tail;
void main()
{
    int c;
    while(1)
    {
        printf("\n\nEnter 1 for creating link list :");
        printf("\nEnter 2 for linear search");
        printf("\nEnter 3 for traverse ");
        printf("\nEnter 4 for Exit");
        printf("\nEnter your choice :");
        scanf("%d",&c);
        switch(c)
        {
            case 1:create();
                break;
            case 2: search();
                break;
            case 3: traverse();
                break;
            case 4: exit(0);
                break;
            default: printf("Please enter a valid input :\n");
        }
    }
}
void create()
{
    new=(struct node *)malloc(sizeof(struct node ));
    printf("\nEnter data:");
    scanf("%d",&new->data);
    new->next=NULL;
    if(head==NULL)
    {
        tail=head=new;
    }
    else
    {
        tail->next=new;
        tail=new;
    }
}
void traverse()
{
    if(head==NULL)
    {
        printf("\n list is empty");
    }
    else
    {
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d-->",temp->data);
    }
    }
}
void search()
{
    int n,r=0,k=0;
    if(head==NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        printf("\nEnter any number to search : ");
        scanf("%d",&n);
        for(temp=head;temp!=NULL;temp=temp->next)
        {  
             r++;
            if(temp->data==n)
            {
                printf("\nData found at position  %d :",r);
                k=1;

            }
        }
        if(k==0)
        {
            printf("\nEntered data is not found");
        }
    }
}
