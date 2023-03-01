#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>> adj;
    
    void addEdge(int u,int v,bool direction)
    {
        adj[u].push_back(v);
        if(direction)
        adj[v].push_back(u);
    }


    void printList()
    {
        for(auto i:adj)
        {
            cout<<i.first<<":";
            for(auto j:i.second)
            {
             cout<<j<<",";
            }
            cout<<endl;
        }
    }

    bool checkCycleUsingBfs()
    {
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        queue<int> q;
        q.push(4);
        visited[4]=true;
        parent[4]=-1;
        while(!q.empty())
        {
            int node=q.front();

            for(auto neighbour:adj[node])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]=1;
                    parent[neighbour]=node;
                }else if(neighbour!=parent[node]){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(unordered_map<int,bool> &visited,int node,int parent){

        visited[node]=1;

        for(auto i:adj[node])
        {
            if(!visited[i])
            {
                bool check=isCycle(visited,i,node);
                if(check)
                return true;
            }else if(i!=parent){
                return true;
            }
        }

        return false;
    }
    bool checkCycleUsingDfs()
    {
        unordered_map<int,bool> visited;

        bool check=isCycle(visited,4,-1);

        return check;
    }
};
int main()
{
    graph g;
    g.addEdge(4,5,true);
    g.addEdge(5,7,true);
    g.addEdge(5,6,true);
    g.addEdge(7,8,true);
    g.addEdge(6,8,true);
    g.addEdge(9,8,true);
    
    cout<<"if cycle is exist or not:"<<g.checkCycleUsingBfs();
    cout<<"if cycle is exist or not:"<<g.checkCycleUsingDfs();
    return 0;
}