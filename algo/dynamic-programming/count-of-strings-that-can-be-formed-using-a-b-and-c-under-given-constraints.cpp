#include <iostream>
using namespace std;

int main() {
	int dp[1001][2][3]={0};
    for(int i=0;i<=1000;i++)
	    dp[i][0][0]=1;
    for(int j=0;j<=1;j++)
	    for(int k=0;k<=2;k++)
	        dp[0][j][k]=1;
	for(int i=1;i<=1000;i++)
	{
	    for(int j=0;j<=1;j++)
	    {
	        for(int k=0;k<=2;k++)
	        {
	            dp[i][j][k]=dp[i-1][j][k];
	            if(j>0)
	                dp[i][j][k]+=dp[i-1][j-1][k];
	            if(k>0)
	                dp[i][j][k]+=dp[i-1][j][k-1];
	        }
	    }
	}
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<dp[n][1][2]<<"\n";
	}
	return 0;
}
