#include<bits/stdc++.h>
using namespace std;


set<int> vis;
void DFS(int i,vector<int> adj[],stack<int> &s)
{
    vis.insert(i);
    for(const auto & x : adj[i])
    {
        if(vis.find(x)==vis.end())
            DFS(x,adj,s);
    }
    s.push(i);
}
int* topoSort(int V, vector<int> adj[])
{
    vis.clear();
    stack<int> s;
    for(int i=0;i<V;i++)
    {
        if(vis.find(i)==vis.end())
            DFS(i,adj,s);
    }
    int* ans = new int[V]();
    int i = 0;
    while(!s.empty())
    {
        ans[i++] = s.top();
        s.pop();
    }
    return ans;
}

int main()
{
  int T;
  cin>>T;
  while(T--)
  {

      int N, E;
      cin>>N>>E;
      vector<int> adj[N];
      bool vis[N] = {false};
      for(int i=0;i<E;i++)
      {
          int u,v;
          cin>>u>>v;
          adj[u].push_back(v);
      }

      int* topoSorted = topoSort(N, adj);
      cout<<endl;
  }
  return 0;
}
