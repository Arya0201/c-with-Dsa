//directed acyclic graph
#include<bits/stdc++.h>
using namespace std;
class graph{
  public:
  unordered_map<int,list<pair<int,int>>> adj;
  int vertex;
  int edges;
  graph(int v,int e)
  {
    this->vertex=v;
    this->edges=e;
  }

  void addEdge(int u,int v,int weight)
  {
      pair<int,int> p= make_pair(v,weight);
      adj[u].push_back(p);
  }
  
   void findShortestPathInDAG(int src)
   {
      vector<bool> visited(vertex);
      stack<int> s;
      
      for (int i = 0; i < vertex; i++)
      {
        if(!visited[i])
        {
            dfs(visited,s,i);
        }
      }


      vector<int> distance(vertex,INT_MAX);
      distance[src]=0;
      while (!s.empty())
      {
         int top=s.top();
         s.pop();

         if(distance[top]!=INT_MAX)
         {
            for (auto i:adj[top])
            {
                
                if(distance[top] + i.second <distance[i.first])
                {
                    distance[i.first]=distance[top] + i.second ;
                    s.push(i.first);
                }
            }
            
         }
      }
      
      for (int i = 0; i < vertex; i++)
      {
        cout<<distance[i]<<" ";
      }
      
   }
   void dfs(vector<bool> &visited,stack<int> &s,int node)
   {
         visited[node]=1;

         for(auto i:adj[node])
         {
            if(!visited[i.first])
            {
                dfs(visited,s,i.first);
            }
         }

         s.push(node);
   }
};
int main()
{
    // Number of Edges and Vertices

    int num_vertices = 6;

    int num_edges = 9;

 

    graph G(num_vertices, num_edges); // Graph G

    

    // add all edges to graph

    G.addEdge(1, 3, 6);

    G.addEdge(1, 2, 2);

    G.addEdge(0, 1, 5);

    G.addEdge(0, 2, 3);

    G.addEdge(3, 4, -1);

    G.addEdge(2, 4, 4);

    G.addEdge(2, 5, 2);

    G.addEdge(2, 3, 7);

    G.addEdge(4, 5, -2);

 

    // compute the Shortest_path

    int src = 1; 

    G.findShortestPathInDAG(src);

    return 0;
}