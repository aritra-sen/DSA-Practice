#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
// O(N^3) solution see binary search folder for O(N log(sum[arr[i]])) time complexity
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int a[n];
    int sum[n]={0};
    for(int i=0;i<n;i++)
      cin>>a[i];
    sum[0]=a[0];
    for(int i=1;i<n;i++)
      sum[i]=sum[i-1]+a[i];
      int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++)
      dp[i][1]=a[0];
    for(int i=1;i<=n;i++)
      dp[1][i]=sum[i-1];

    for(int i=2;i<=k;i++) // number of partitions
    {
      for(int j=2;j<=n;j++) // number of boards to paint
      {
        dp[i][j] = INT_MAX;
        for(int p = 1;p<=j;p++)
          dp[i][j] = min(dp[i][j],max(dp[i-1][p],sum[j-1]-sum[p-1]));
      }
    }
    cout<<dp[k][n]<<"\n";
  }
  return 0;
}
