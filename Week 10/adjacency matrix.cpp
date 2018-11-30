
#include<bits/stdc++.h>
using namespace std;
#define cap 20
int adj[cap][cap];
bool pathchecking(int a,int b,int v)
{
    if(a==b)
        return true;
    queue<int> q;
    int visited[v];
    for(int i=0;i<v;i++)
        visited[i]=0;
    visited[a]=1;
    q.push(a);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(adj[t][b]==1)
            return true;
        for(int i=0;i<v;i++)
        {

            if(adj[t][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                q.push(i);
            }
        }
    }
    return false;
}

int main(){

	int n,t=0;
	cin>>n;
	for(int i=0;i<n;i++)
	     for(int j=0;j<n;j++)
            cin>>adj[i][j];
	for(int i=0;i<n;i++)
	{
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]==0 && i!=j)
                t++;
        }
	}
	if(t>0)
        cout<<"It is an incomplete graph\n";
    else
        cout<<"It is a complete graph\n";
    cout<<"Enter the choice:\n";
    cout<<"1. For Directed Graph\n";
    cout<<"2. For Undirected Graph\n";
    int c;
    cin>>c;
    if(c==2)
    {
        cout<<"Enter the vertex number:\n";
        int v,deg=0;
        cin>>v;
        for(int i=0;i<n;i++)
        {
            if(adj[v][i]==1)
                deg++;
        }
        printf("%d is the degree of the given vertex.\n",deg);
    }
    else
    {
        cout<<"Enter the vertex number:\n";
        int v,indeg=0,outdeg=0;
        cin>>v;
        for(int i=0;i<n;i++)
        {
            if(adj[v][i]==1)
                outdeg++;
        }
        for(int i=0;i<n;i++)
        {
            if(adj[i][v]==1)
                indeg++;
        }
        printf("Indegree = %d \nOutdegree = %d\n",indeg,outdeg);
    }
    cout<<"Enter 2 vertices to check the existence of path:\n";
    int a,b;
    cin>>a>>b;
    if(pathchecking(a,b,n))
        cout<<"Path exists";
    else
        cout<<"Path doesn't exist";
  	return 0;
}



