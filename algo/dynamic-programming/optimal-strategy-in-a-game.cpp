#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    int dp[n][n];
    for(int i=0;i<n;i++)
      dp[i][i] = a[i];
    for(int i=0;i<n-1;i++)
      dp[i][i+1] = max(a[i],a[i+1]);
    for(int d=3;d<=n;d++)
    {
      for(int i=0;i<=n-d;i++)
      {
        int j = i + d - 1;
        dp[i][j] = max(a[i] + min(dp[i+1][j-1],dp[i+2][j]),a[j] + min(dp[i+1][j-1],dp[i][j-2]));
      }
    }
    cout<<dp[0][n-1]<<"\n";
  }
  return 0;
}
