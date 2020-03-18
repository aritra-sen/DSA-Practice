{
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {

	int t;
	cin >> t;

	while(t--){

	    int v, e;
	    cin >> v >> e;

	    vector<int> adj[v];

	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }

	    cout << isCyclic(v, adj) << endl;

	}

	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

void isCyclicUtil(vector<int> adj[],int vis[],int i,bool &hasCycle)
{
  if(hasCycle)
    return ;
  vis[i] = 1;
  for(int j = 0; j<adj[i].size();j++)
  {
    int next = adj[i][j];
    if(vis[next]==0)
      isCyclicUtil(adj,vis,next,hasCycle);
    else if(vis[next]==1)
    {
      hasCycle = true;
      break;
    }
  }
  vis[i] = 2;
}

bool isCyclic(int V,vector<int> adj[])
{
  int vis[V]={0};
  bool ans = false;
  for(int i=0;i<V;i++)
  {
    if(vis[i]==0)
        isCyclicUtil(adj,vis,i,ans);
    if(ans)
        break;
  }
  return ans;
}
