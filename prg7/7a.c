#include<stdio.h>

int a[10][10],visit[10],con[20],j=0,acy=1,n,c=0;

void dfs(int s)
{
	visit[s]=1;con[j++]=s;
	for(int i=s;i<=n;i++,c++)
	{	
		if(a[s][i]&&visit[i])
			acy=0;
		if(a[s][i]&&!visit[i])
			dfs(i);
	}
}

void concyc()
{
	int i,f=1;
	for(i=1;i<=n;i++)
		if(!visit[i])
		{
			f=0;con[j++]=0;
			dfs(i);
		}
	if(f)
		printf("Graph is connected\n");
	else
	{
	    int cc=1;
		printf("Graph is not connected\n{");
		for(int i=0;i<j;i++)
		    if(!con[i])
		    {
		        cc++;
		        printf(" }{ ");
		    }
		    else
		     printf(" %d ",con[i]);
	    printf(" }\nThere are %d connected component\n",cc);
	}
	if(acy)
		printf("Graph is Acyclic\n");
	else
		printf("Graph is Cyclic\n");	
}
void main()
{
	int i,j;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		visit[i]=0;
	printf("Enter the adjacency matrix : \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	dfs(1);
	concyc();
	printf("The operation count is : %d\n",c);
}

