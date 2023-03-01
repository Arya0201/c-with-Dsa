#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,vector<int> &disc,vector<int> &low,vector<bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &ap,int &timer)
{
    visited[node]=1;
    disc[node]=low[node]=timer++;
    int cnt=0;
    for (auto neighbour:adj[node])
    {
         if(neighbour==parent)
         continue;

         if(!visited[neighbour])
         {
             dfs(neighbour,node,disc,low,visited,adj,ap,timer);
             low[node]=min(low[node],low[neighbour]);
             if(low[neighbour] >=disc[node] && parent!=-1)
             {
                ap[node]=1;
             }
             cnt++;
         }else{
            low[node]=min(low[node],disc[neighbour]);
         }
    }

    if(cnt>1 && parent==-1)
    {
        ap[node]=1;
    }
}

int main()
{   
    int n=5;
    int e=5;
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(n);
    vector<int> low(n);
    int parent=-1;
    vector<bool>  visited(n);
    int timer=0;
    
    vector<int> ap(n,0);

    for (int i = 0; i < n; i++)
    {
        disc[i]=-1;
        low[i]=-1;
        visited[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i,-1,disc,low,visited,adj,ap,timer);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if(ap[i]==1)
        cout<<i<<"\t";
    }
    
    return 0;
}