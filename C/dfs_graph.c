#include <stdio.h>

int G[5][5],visited[5],n; 

int main()
{
    int i,j;
    printf("Enter number of vertices:");
   
    scanf("%d",&n);
 
    //read the adjecency matrix
    printf("\nEnter adjecency matrix of the graph:");
   
    for (i=0;i<n;i++)
       for (j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
    for (i=0; i<n; i++)
        visited[i] = 0;    

    return 0;
}
