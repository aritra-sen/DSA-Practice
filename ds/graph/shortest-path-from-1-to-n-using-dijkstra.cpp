#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 1000000

typedef pair<int,int> Pair;


int main() {
	vector<int> dist(10001, INF);
    vector<vector<int>> adj(10001);
	for(int i=1;i<=10000;i++)
	{
	    if(3*i<=10000)
	        adj[i].push_back(3*i);
	    if(i+1<=10000)
	        adj[i].push_back(i+1);
	}

	priority_queue<Pair,vector<Pair>,greater<Pair>> pq;
	pq.push({0,1});

	dist[1] = 0;
	bool vis[10001] = {false};
	while(!pq.empty())
	{
	    Pair top = pq.top();
	    pq.pop();
	    if(vis[top.second])
	        continue;
	    vis[top.second] = true;

	    for(int i=0;i<adj[top.second].size();i++)
	    {
	        int node = adj[top.second][i];
	        if(vis[node] == false)
	        {
	            if(dist[node] > (dist[top.second] + 1))
	            {
                    dist[node] = dist[top.second] + 1;
                    pq.push({dist[node],node});
	            }
            }
	    }
	}
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<dist[n]<<"\n";
	}
	return 0;
}
