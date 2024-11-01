// MIN HEAP implemtation using arrays..
#include<stdio.h>
#include<stdlib.h>
#define max 20
int n=0;
int heap[max];



void create();// function declerations..
void insert();
void delete();
void traverse();
void main()
{
    printf("\n\n *** Implementation of MIN HEAP usinfg arrays ***\n");
    int c;
    create();
    while(1)
    {
        printf("\n1 for insert\n2 for delete \n3for traverse\n4for Exit..");
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1: insert();
                break;
            case 2:delete();
                break;
            case 3:traverse();
                break;
            case 4: printf("\ncode implemented sucessfully...");
                exit(0);
                break;
            default: printf("Enter a valid input :");
        }
    }
}
void create()
{
    int size;
    printf("\nEnter the size..(i.e no of nodes):");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        insert();
    }
}
void insert()
{
    printf("\nEnter  data :");
    scanf("%d",&heap[n]);
    int i=n;
    n++;
    while(i>=1)
    {
        int parent=(i-1)/2;
        if(heap[parent]>heap[i])
        {
            int temp=heap[parent];
            heap[parent]=heap[i];
            heap[i]=temp;
            i=parent;
        }
        else
        {
            return;
        }
    }
}
void delete()
{
    n--;
    heap[0]=heap[n];
    n--;// last empty node deleted..
    int i=0;
    while(i<n)
    {
     int smallest=i;
            int left=(2*i)+1;
            int right=(2*i)+2;
            if(left<n && heap[left]<heap[smallest])
            {
                smallest=left;
            }
            if(right<n && heap[right]<heap[smallest])
            {
                smallest=right;
            }
            if(smallest!=i)
            {
                int temp = heap[i];
                heap[i] = heap[smallest];
                heap[smallest] = temp;
                i = smallest;
            }
            else
            {
            return;
            }  
        }
}
     
void traverse()
{
    printf("\nData in the heap : ");
    for(int i = 0; i<n; i++)
    {
        printf("%d ",heap[i]);
    }
}

