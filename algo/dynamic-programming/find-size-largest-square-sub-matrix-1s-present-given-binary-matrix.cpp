#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>a[i][j];
    int dp[n][m];
    int ans = 1;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
          dp[i][j]=a[i][j];
          if(i>0 && j>0 && a[i][j]==1)
            dp[i][j]=1 + min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
          ans = max(ans,dp[i][j]);
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
