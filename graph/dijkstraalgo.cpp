//unordered graph
#include<bits/stdc++.h>
using namespace std;
class graph{
 public:
  unordered_map<int,list<pair<int,int>>> adj;
  int vectex;
  int edges;

  graph(int v,int e)
  {
    this->vectex=v;
    this->edges=e;
  }

  void addEdges(int u,int v,int w)
  {
     adj[u].push_back(make_pair(v,w));
     adj[v].push_back(make_pair(u,w));
  }

  vector<int> dijkstra(int src)
  {
      vector<int> distance(vectex,INT_MAX);
      distance[src]=0;
      set<pair<int,int>> s;
      s.insert(make_pair(0,src));

      while (!s.empty())
      {
        pair<int,int> top=*(s.begin());
        int node=top.second;
        int dis=top.first;

        s.erase(s.begin());
        
        for (auto i:adj[node])
        {
            if( dis + i.second< distance[i.first])
            {
                auto record=s.find(make_pair(distance[i.first],i.first));

                if(record!=s.end())
                {
                    s.erase(record);
                }

                distance[i.first]=dis+i.second;

                s.insert(make_pair(distance[i.first],i.first));
            }
        }
        
      }
      
      return distance;
  }
};
int main()
{   
  graph g(4,5);
  g.addEdges(1,0,5);
  g.addEdges(0,2,8);
  g.addEdges(2,3,6);
  g.addEdges(1,3,2);
  g.addEdges(1,2,9);
  
  vector<int> ans=g.dijkstra(0);
  for(auto i:ans)
  {
    cout<<i<<":";
  }
    return 0;
}