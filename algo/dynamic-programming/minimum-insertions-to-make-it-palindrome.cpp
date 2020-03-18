#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string x;
    cin>>x;
    int n = x.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
      dp[i][i]=0;
    for(int i=1;i<n;i++)
      dp[i-1][i]=x[i-1]==x[i]?0:1;
    for(int d = 3;d<=n;d++)
    {
      for(int i = 0;i<=n-d;i++)
      {
        int j = i+d-1;
        if(x[i]==x[j])
          dp[i][j] = dp[i+1][j-1];
        else
          dp[i][j] = min(dp[i+1][j],dp[i][j-1]) + 1;
      }
    }
    cout<<dp[0][n-1]<<"\n";
  }
  return 0;
}
