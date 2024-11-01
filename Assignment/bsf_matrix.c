//Implementation of bfs using adjacency matrix
#include<stdio.h>
#include<stdlib.h>
#define n 5
int adj[n][n];
int queue[n];
int visited[n]={0};
int rear=0,front=0;
void addedge(int ,int ); // function declerations..
void bfs(int);

void main()
{
    printf("\n *** Implenentation of BFS using adjacency matrix ***");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j]=0;// first assigining zero
        }
    }
    for(int i=0;i<n;i++)
    {
        int a,b;
        printf("\nEnter the edges:(a,b):");
        scanf("%d%d",&a,&b);
        addedge(a,b);
    }
    int t;
    printf("Enter a source node :");
    scanf("%d",&t);
    printf("\nBSF Traversal is :\n");
    bfs(t);// initially selecting source node as 1.. 
}
void addedge(int source,int dest)
{
    adj[source][dest]=1;//  assigning 1 that-->indecates the presence of element 
    adj[dest][source]=1;
}
void bfs(int start)// bsf fallows queue...
{
    queue[rear++]=start;
    visited[start]=1;// making node as visited..
    while(front<rear)
    {
        int current=queue[front++];// storing that variable ,,and deleting that data from queue..
        printf("%d ",current);
        for(int i=0;i<n;i++)
        {
            if(adj[current][i]==1 && visited[i]==0)
            {
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
}
