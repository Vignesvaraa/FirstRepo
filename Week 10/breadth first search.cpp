#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v;
    cout<<"Enter the number of vertices in the graph:\n";
    cin>>v;
    int adj[v][v];
    cout<<"Enter the graph:\n";
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>adj[i][j];
    queue<int> q;
    int s;
    cout<<"Enter the source node:\n";
    cin>>s;
    int visited[v],distance[v];
    for(int i=0;i<v;i++)
        visited[i]=0;
    visited[s]=1;
    distance[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int t=q.front();
        cout<<t<<" ";
        cout<<"Shortest Distance = "<<distance[t]<<" ";
        q.pop();
        for(int i=0;i<v;i++)
        {
            if(adj[t][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                distance[i]=distance[t]+1;
                q.push(i);
            }
        }
    }
    return 0;
}



