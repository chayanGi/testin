#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
int mindist(int d[],bool ss[],int V)
{
    int min=__INT_MAX__ ;
    int minindex;
for (int v = 0; v < V;v++)   
{
        if(ss[v]==false && d[v]<=min)
        {min=d[v];
        minindex=v;
        }
        return minindex;
    }
}
void print(int d[], int V)
{
    printf("vertex \t distance \n");
    for(int i=0;i<V;i++)
    {printf("%d \t %d\n",i,d[i]);
    }
}
void dijkstra(int g[][10], int s,int V)
{
    int d[V];
    bool ss[V];
     for (int i = 0; i < V; i++)
        d[i] =__INT_MAX__, ss[i] = false;
    d[s]=0;
    for(int c=0;c<V-1;c++)
    {
        int u=mindist(d,ss,V);
        ss[u]=true;
         for (int v = 0; v < V; v++)
         if (!ss[v] && g[u][v] && d[u] != __INT_MAX__ && d[u] + g[u][v] < d[v])
         d[v]=d[u]+g[u][v];
    }
    print(d,V);
}
void main()
{   int V,i,j;
  printf("enter the no of nodes of graph  ");
  scanf("%d",&V);
  int g[V][V];
  printf("enter the graph  ");
  for( i=0;i<V;i++)  
  {
      for(j=0;j<V;j++)
      scanf("%d",&g[i][j]);
  }
  dijkstra(g,0,V);
}