#include<stdio.h>
#include<stdlib.h>
void traverse();
void insert();
void create();
void delete();
#define max 10
int heap[max],n=0;

void main()
{
    printf("\nprogram of heap :\n");
    create();
    int c;
    while(1)
    {
        printf("\nEnter \n 1 for insert :");
        printf("\n2 for delete :");
        printf("\n3 for traverse");
        printf("\n Enter choice :");
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
    printf("\nEnter the size (i.e nodes):");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        insert();
    }
}
void insert() // max heap
{
    scanf("%d",&heap[n]); //4,8 
    int i=n;
    n++;
    while(i>=1)
    {
        int parent=(i-1)/2;
        if(heap[parent]<heap[i])
        {
            int temp=heap[parent];
            heap[parent]=heap[i];
            heap[i]=temp;
            i=parent;// 

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
    int i=0;
    n--;
    while(i<n)
    {
        int largest=i;
        int left=(2*i)+1;
        int right=(2*i)+2;
        if(left<n && heap[left]>heap[largest])
        {
            largest=left;
        }
        if(right<n && heap[right]>heap[largest])
        {
            largest=right;
        }
        if(largest!=i)
        {
          int temp=heap[largest];
          heap[largest]=heap[i];
          heap[i]=temp;
        }
        else
        {
            return;
        }
    }
}
void traverse()
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",heap[i]);
    }
}








