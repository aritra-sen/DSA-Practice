#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    queue<int> q;
	    int vis[n]={0};
	    q.push(0);
	    vis[0]=0;
	    while(!q.empty() && vis[n-1]==0)
	    {
	        int top = q.front();
	        q.pop();
	        for(int i=1;i<=a[top];i++)
	        {
	            if((top+i)<n && vis[top+i]==0)
	            {
	                q.push(top+i);
	                vis[top+i]=1+vis[top];
	            }
	        }
	    }
	    if(vis[n-1])
	        cout<<vis[n-1]<<"\n";
	    else
	        cout<<"-1\n";
	}
	return 0;
}
