//code studio 
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
public:
     unordered_map<T,list<T>> adj;
     void addEdge(T u,T v,bool direction)
     {
         //direction 0 ->undirected graph 
         //direction 1->directed graph
         adj[u].push_back(v);

         if(direction==0)
         {
            adj[v].push_back(u);
         } 
     }

     void printList()
     {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
     }
};
void bfs(unordered_map<int,set<int>> &mp, unordered_map<int,bool> &visited,vector<int> &ans,int node)
{
    queue<int> q;
    q.push(node);
    visited[node]=1;
    
    while(!q.empty())
    {
        int frontnode=q.front();
        q.pop();
        ans.push_back(frontnode);
        
        for(auto i:mp[frontnode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int,set<int>>mp;
    vector<int> ans;
    
    for(int i=0;i<edges.size();i++)
    {
       int u=edges[i].first;
        int v=edges[i].second;
        mp[u].insert(v);
        mp[v].insert(u);
    }
    
    unordered_map<int,bool> visited;
    
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
        {
            bfs(mp,visited,ans,i);
        }
    }
    return ans;
}

int main()
{   int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of Edges"<<endl;
    cin>>m;
    
    graph<int> g;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //creating undirected graph
        g.addEdge(u,v,0);
    }

    //printing graph
    g.printList();
    return 0;
}
