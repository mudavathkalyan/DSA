// implementation of dsf using adjacency list..
#include<stdio.h>
#include<stdlib.h>
#define n 5

int adj[n][n];
int stack[n];
int visited[n]={0};
int top=-1;
void addedge(int ,int);
void dfs(int);
void main()
{
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
            adj[i][j]=0;
    	}
    	
    }
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the edges:");
        int a,b;     
        scanf("%d%d",&a,&b);
        addedge(a,b);
    }
    int t;
    printf("\nEnter the source node:");
    printf("\nDFS traversal is :\n");
    scanf("%d",&t);
    dfs(t);
}
void addedge(int src,int dest)
{
	adj[src][dest]=1;
	adj[dest][src]=1;
}
void dfs(int source)
{
    int t;
    stack[++top]=source;
    while(top>=0)
    {
        t=stack[top--];
        if(visited[t]==0)
        {
            printf("%d ",t);
            visited[t]=1;
        
            for(int i=0;i<n;i++)
            {
                if(adj[t][i]==1 && visited[i]==0)
                {
                    stack[++top]=i;
                }
            }
        }
    }
}
