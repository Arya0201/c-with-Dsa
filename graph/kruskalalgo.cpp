#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
     vector<vector<int>> edges;
     int n;
     graph(int n)
     {
       this->n=n;
     }
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[2]<b[2];
    }
    void addEdges(int u,int v,int w)
    {
        edges.push_back({u,v,w});
    }
    
    void makeSet(vector<int> &parent,vector<int> &rank)
    {
        for(int i=0;i<n;i++)
        {
          parent[i]=i;
          rank[i]=0;
        }
    }
   void mst_kruskal()
   {
     sort(edges.begin(),edges.end(),cmp);
     vector<int> parent(n);
     vector<int> rank(n);

     makeSet(parent,rank);
     int minWidth=0;

     for(int i=0;i<n;i++)
     {
        int u=findParent(parent,edges[i][0]);
        int v=findParent(parent,edges[i][1]);
        int w=edges[i][2];

        if(u!=v)
        {
            minWidth+=w;
            unionSet(u,v,parent,rank);
        }
     }

     cout<<minWidth;
   } 
   void unionSet(int u,int v,vector<int> &parent,vector<int> &rank)
   {
       u=findParent(parent,u);
       v=findParent(parent,v);

       if(rank[u] > rank[v])
       {
        parent[v]=u;
       }else if(rank[v] > rank[u])
       {
        parent[u]=v;
       }else{
        parent[v]=u;
        rank[u]++;
       }
   }
   int findParent(vector<int> &parent,int node)
   {
     if(parent[node]==node)
     return node;

     return parent[node]=findParent(parent,parent[node]);
   }
};
int main()
{   
    graph g(4);
    g.addEdges(0,1,3);
    g.addEdges(0,3,5);
    g.addEdges(1,2,1);
    g.addEdges(2,3,8);
    
    g.mst_kruskal();
    return 0;
}