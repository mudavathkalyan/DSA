#include<stdio.h>
#include<stdlib.h>
void reverse();
void traverse();
struct node
{
    int data;
    struct node *next;
}*head=NULL,*new,*temp,*temp1,*ptr;
void main()
{   
    int n=1;
    while(n)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data:");
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL)
        {
            temp=head=new;
        }
        else
        {
            temp->next=new;
            temp=new;
        }
        printf("\nEnter 1 for continue adding nodes or  0  to stop ");
        scanf("%d",&n);
    }
    printf("\nEnterd link is :");
    traverse();
    reverse();
    printf("\n\nReverse of linl list is :");
    traverse();
}

void reverse()
{
    temp=head;
    ptr=NULL;
    while(temp!=NULL)
    {
        temp1=temp->next;
        temp->next=ptr;
        ptr=temp;
        temp=temp1;
    }
    head=ptr;
}

void traverse()
{
    if(head==NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            printf("%d-->",temp->data);
        }
    }
}