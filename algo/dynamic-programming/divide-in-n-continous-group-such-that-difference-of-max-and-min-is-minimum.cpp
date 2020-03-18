#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

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
    int maxP[k+1][n+1];
    int minP[k+1][n+1];
    for(int i=1;i<=k;i++)
    {
        dp[i][1]=a[0];
        maxP[i][1]=a[0];
        minP[i][1]=a[0];
    }
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=sum[i-1];
        maxP[1][i]=sum[i-1];
        minP[1][i]=sum[i-1];
    }

    for(int i=2;i<=k;i++) // number of partitions
    {
      for(int j=2;j<=n;j++) // number of boards to paint
      {
        dp[i][j] = INT_MAX;
        for(int p = 1;p<=j;p++)
        {
            int maximum = max(maxP[i-1][p],sum[j-1]-sum[p-1]);
            int minimum = min(minP[i-1][p],sum[j-1]-sum[p-1]);
            if(dp[i][j] > (maximum - minimum))
            {
              dp[i][j] = maximum - minimum;
              maxP[i][j] = maximum;
              minP[i][j] = minimum;
            }
        }
      }
    }
    /*
    for(int i=1;i<=k;i++) // number of partitions
    {
      for(int j=1;j<=n;j++) // number of boards to paint
        cout<<dp[i][j]<<" ";
      cout<<endl;
    }
    */
    cout<<dp[k][n]<<"\n";
  }
  return 0;
}
