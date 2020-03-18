#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    queue<int> q;
	    vector<int> a(n+1);
	    for(int i=1;i<=n;i++)
	    {
	        a[i] = i;
	        q.push(i);
	    }
	    int i = 1;
	    while(!q.empty())
	    {
	        for(int j=1;j<=i;j++)
	        {
	            int x = q.front();
	            q.pop();
	            q.push(x);
	        }
	        a[q.front()] = i++;
	        q.pop();
	    }
	    for(i=1;i<=n;i++)
	        cout<<a[i]<<" ";
	    cout<<"\n";
	}
	return 0;
}
