#include<iostream>
#include<queue>
using namespace std;


int* topoSort(int V, vector<int> adj[])
{
    bool vis[V]={false};
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++)
      for(int x : adj[i])
        indegree[x]++;

    queue<int> q;
    for(int i=0;i<V;i++)
    {
      if(indegree[i]==0)
      {
        q.push(i);
        vis[i] = true;
      }
    }
    int* ans = new int[V]();
    int i = 0;
    while(!q.empty())
    {
      int top = q.front();
      ans[i++] = top;
      q.pop();
      for(int x : adj[top])
      {
        indegree[x]--;
        if(indegree[x]==0)
        {
          q.push(x);
          vis[x]=true;
        }
      }
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
