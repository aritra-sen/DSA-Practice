#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>k;
	    cin>>n;
	    long a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    long dp[k+1][n+1];
	    memset(dp,0,sizeof(dp));
	    for(int i=1;i<=k;i++)
	    {
          int prev_diff = INT_MIN;
	        for(int j=2;j<=n;j++)
	        {
	            dp[i][j] = dp[i][j-1];
              prev_diff = max(prev_diff,dp[i-1][j-1] - a[j-2]);
              /*
	            for(int k = 1;k<j;k++)
	            {
	                int profit = a[j-1] - a[k-1];
	                dp[i][j] = max(dp[i][j],dp[i-1][k-1] + profit);
	            }*/
              dp[i][j] = max(dp[i][j],a[j-1] + prev_diff);
	        }
	    }
	    cout<<dp[k][n]<<"\n";
	}
	return 0;
}
