#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    int mat[m][n];
	    for(int i=0;i<m;i++)
	        for(int j=0;j<n;j++)
	            cin>>mat[i][j];
	    int dp[m][n];
	    dp[m-1][n-1] = mat[m-1][n-1]>0?1:1-mat[m-1][n-1];
	    for(int i=n-2;i>=0;i--)
	        dp[m-1][i]=max(dp[m-1][i+1]-mat[m-1][i],1);
	    for(int i=m-2;i>=0;i--)
	        dp[i][n-1]=max(dp[i+1][n-1]-mat[i][n-1],1);
	    for(int i=m-2;i>=0;i--)
	    {
	        for(int j=n-2;j>=0;j--)
	        {
	            int min_points_on_exit = min(dp[i+1][j],dp[i][j+1]);
	            dp[i][j] = max(1,min_points_on_exit-mat[i][j]);
	        }
	    }
	    cout<<dp[0][0]<<"\n";
	}
	return 0;
}
