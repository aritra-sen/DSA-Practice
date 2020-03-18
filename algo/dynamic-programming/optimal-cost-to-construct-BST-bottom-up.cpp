#include<iostream>
#include<climits>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int freq[n];
    for(int i=0;i<n;i++)
      cin>>freq[i];
    int dp[n][n];
    int sum[n];
    sum[0]=freq[0];
    for(int i=0;i<n;i++)
      dp[i][i] = a[i];
    for(int i=0;i<n-1;i++)
      sum[i+1] = sum[i]+a[i+1];
    for(int d=2;d<=n;d++)
    {
      for(int i=0;i<=n-d;i++)
      {
        int j = i + d - 1;
        dp[i][j] = INT_MAX;
        for(int k = i;k<=j; k++)
        {
          int left = k>i?dp[i][k-1]?0;
          int right = k<j?dp[k+1][j]?0;
          int val = i==0?sum[j]:(sum[j] - sum[i-1]);
          dp[i][j] = min(dp[i][j],left + right + val);
        }
      }
    }
    cout<<dp[0][n-1]<<"\n";
  }
  return 0;
}
