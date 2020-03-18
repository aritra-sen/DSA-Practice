#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    bool dp[n][m];
	    memset(dp,0,sizeof(dp));
	    dp[0][a[0]%m]=true;
	    for(int i=1;i<n;i++)
	        for(int j=0;j<m;j++)
	            dp[i][j] = dp[i-1][j] || dp[i-1][(j - a[i]%m + m)%m];
	    cout<<dp[n-1][0]<<"\n";
	}
	return 0;
}
