#include<iostream>
#include<cstring>
using namespace std;

/*
//o(N^3) sol
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n,X;
    cin>>m>>n>>X;
    long dp[n+1][X+1];
    dp[0][0] = 1;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=X && i<=m;i++)
        dp[1][i] = 1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=X;j++)
        {
            for(int k = 1;k<=m && k<j;k++)
                dp[i][j] += dp[i-1][j-k];
        }
    }
    cout<<dp[n][X]<<"\n";
  }
}

*/

// O(N^2) Soln
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n,X;
    cin>>m>>n>>X;
    long dp[n+1][X+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=X;j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            if(j-m-1>=0)
                dp[i][j]-=dp[i-1][j-m-1];
        }
    }
    cout<<dp[n][X]<<"\n";
  }
}
