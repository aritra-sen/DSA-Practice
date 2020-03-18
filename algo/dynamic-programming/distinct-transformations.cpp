#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string x,y;
	    cin>>x>>y;
	    int n = x.size(),m = y.size();
	    int dp[n+1][m+1];
	    dp[0][0] = 1;
	    for(int i=1;i<=n;i++)   dp[i][0]=1;
	    for(int i=1;i<=m;i++)   dp[0][i]=0;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            if(x[i-1]==y[j-1])
	                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	            else
	             dp[i][j] = dp[i-1][j];
	       }
	    }
	    cout<<dp[n][m]<<"\n";
	}
	return 0;
}
