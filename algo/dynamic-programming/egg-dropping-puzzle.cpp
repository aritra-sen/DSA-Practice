#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int k,n;
    cin>>k>>n;
    int dp[n+1][k+1];
    for(int i=0;i<=k;i++)
    {
      dp[0][i]=0;
      dp[1][i]=1;
    }
    for(int i=1;i<=n;i++)
        dp[i][1]=i;
    for(int i=2;i<=n;i++)
    {
      for(int j=2;j<=k;j++)
      {
          int ans = 1000000;
          for(int z=1;z<=i;z++)
              ans = min(ans,max(dp[z-1][j-1],dp[i-z][j]));
          dp[i][j]=1+ans;
      }
    }
    cout<<dp[n][k]<<"\n";
  }
  return 0;
}
