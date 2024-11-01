// max heap implementation using arrays...
#include<stdio.h>
#include<stdlib.h>
#define max 20
int heap[max],n = 0;
void insert();
void delete();
void traverse();
void create();
void swap();

void main()
{
    printf("\n\n *** implementation of MAX heap using arrays ****\n\n");
    int c;
    create();//here create function is called and  binary tree is created..
     while(1)
     {
        printf("\n ENTER -->\n1.Insert\n2. Delete\n3.traverse\n4.Exit\n");
        printf("Enter ur choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : insert();
            break;
            case 2 : delete();
            break;
            case 3: traverse();
            break;
            case 4 : printf("\n Program successfully executed\n");
                exit(0);
            break;
            default : printf("\nInvalid choice\n");
        }
    }
}
void create()
{
    int size;
    printf("\nEnter the size..(i.e number of nodes):");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        insert();
    }

}
void insert()
{
    printf("\nEnter data:");
    scanf("%d",&heap[n]);
    int i=n;
    n++;// to store next data in next index ,n is incermented..
    while(i>=1)
    {
        int parent=(i-1)/2;
        if(heap[parent]<heap[i])// swaping
        {
            swap(parent,i);
            i=parent;// like an decrement condition...
        }
        else
        {
            return;
        }
    }

}
void delete()
{
        heap[0]=heap[n-1];
        n--;// deleting last node..
        int i=0;// heapifing from zero index..
        while(i<n)// till last index we compare..
        {
            int parent=i;
            int left=(2*i)+1;
            int right=(2*i)+2;
            if(left<n && heap[left]>heap[parent])
            {
                parent=left;
            }
            if(right<n && heap[right]>heap[parent])
            {
                parent=right;
            }
            if(parent!=i)
            {
                swap(parent,i);
                i = parent;
            }
            else
            {
            return;
            }
        }
}
void swap(int parent,int i)
{
        int t=heap[parent];
        heap[parent]=heap[i];
        heap[i]=t;
}
void traverse()
{
    printf("\n---->The heapifed tree is :\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",heap[i]);
    }
}

