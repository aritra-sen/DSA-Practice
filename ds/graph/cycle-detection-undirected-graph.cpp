
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

void isCyclicUtil(vector<int> adj[],int vis[],int i,int parent,bool &hasCycle)
{
  if(hasCycle)
    return ;
  vis[i] = 1;
  for(int j = 0; j<adj[i].size();j++)
  {
    int next = adj[i][j];
    if(vis[next]==0)
      isCyclicUtil(adj,vis,next,i,hasCycle);
    else if(vis[next]==1 && next!=parent)
    {
      hasCycle = true;
      break;
    }
  }
  vis[i] = 2;
}

bool isCyclic(vector<int> adj[], int V)
{
  int vis[V]={0};
  bool ans = false;
  for(int i=0;i<V;i++)
  {
    if(vis[i]==0)
        isCyclicUtil(adj,vis,i,-1,ans);
    if(ans)
        break;
  }
  return ans;
}
