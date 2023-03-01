//find shorted path from 1 to 6 partinculer node
#include<bits/stdc++.h>
using namespace std;
class graph
{
    public:
  int vertex;
  int edge;
  unordered_map<int,list<int>> adj;
  graph(int v,int e)
  {
    this->vertex=v;
    this->edge=e;
  }

  void addedge(int u,int v)
  {
     adj[u].push_back(v);
     adj[v].push_back(u);
  }

  void shortpath(int src,int des)
  {
       vector<int> parent(vertex+1);
       vector<bool> visited(vertex+1);

       parent[src]=-1;
       queue<int> q;
       q.push(src);
       visited[src]=1;

       while(!q.empty())
       {
        int top=q.front();
        q.pop();

        for (auto i:adj[top])
        {
            if(!visited[i])
            {
                visited[i]=1;
                parent[i]=top;
                q.push(i);
            }
        }
        
       }
       vector<int> ans;
       int currrentnode=des;
       ans.push_back(currrentnode);
      while (currrentnode!=src)
      {
        currrentnode=parent[currrentnode];
        ans.push_back(currrentnode);
      }
      reverse(ans.begin(),ans.end());

      for(auto i:ans)
      {
        cout<<i<<":";
      }
  }

   
};
int main()
{
    graph g(8,9);

    g.addedge(1,2);
    g.addedge(2,5);
    g.addedge(5,8);
    g.addedge(7,8);
    g.addedge(6,7);
    g.addedge(4,6);
    g.addedge(1,4);
    g.addedge(1,3);
    g.addedge(3,8);

   g.shortpath(1,8);
    return 0;
}