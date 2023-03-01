#include<bits/stdc++.h>
using namespace std;
class graph
{
  public:
  int vertex;
  int edges;
  unordered_map<int,list<int>> adj;

  graph(int v,int e)
  {
    this->vertex=v;
    this->edges=e;
  }

  void addEdge(int u,int v)
  {
    adj[u].push_back(v);
  }
 
 void topologySort()
 {
    vector<int> indegre(vertex,0);
    for (int i = 0; i < vertex; i++)
    {
        for (auto neighbour:adj[i])
        {
            indegre[neighbour]++;
        }
        
    }
    queue<int> q;
    for(int i=0;i<vertex;i++)
    {
        if(indegre[i]==0)
        {
            q.push(i);
        }
    }
     vector<int> ans;
     while(!q.empty())
     {
        int top=q.front();
        q.pop();
        ans.push_back(top);

        for(auto i:adj[top])
        {
            indegre[i]--;
            if(indegre[i]==0)
            {
                q.push(i);
            }
        }
     }


     for(auto i:ans)
     {
        cout<<i<<":";
     }
 }

};
int main()
{
    graph g(4,4);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,2);
    
    g.topologySort();
    return 0;
}