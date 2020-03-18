#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N, E;
        cin>>N>>E;

        vector<int> g[N];
        int arrival[N];
        int dept[N];

        memset(vis, false, sizeof(vis));

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=0;i<V:i++)
        {
          arrival[i]=-1;
          dept[i]=-1;
        }
        int x = 0;
        dfs(0,g,vis,x);

        for(int i=0;i<V:i++)
          cout<<"Arrival at "<<arrival[i]<<" and Departure at "<<dept[i]<<"\n";
        cout<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/
void dfs(int s, vector<int> g[], bool vis[],int &time)
{
  arrival[s]=time++;
  cout<<s<<" ";
  for(int i=0;i<g[s].size();i++)
  {
    if(!vis[g[s][i]])
      dfs(g[s][i],g,vis,time);
  }
  dept[s]=time++++;
}
