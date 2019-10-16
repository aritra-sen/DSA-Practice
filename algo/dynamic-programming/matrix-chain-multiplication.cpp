#include<iostream>
using namespace std;
#define INF 1000000000001

int main()
{
  long t;
  cin>>t;
  while(t--)
  {
    long n;
    cin>>n;
    long dim[n+1];
    // if dim[] = {10,30,5,60} we have matrix as 10x30,30x5,5x60
    for(long i=0;i<=n;i++)
        cin>>dim[i];
    long dp[n+1][n+1];
    for(long i=1;i<=n;i++)
      dp[i][i]=0;
    for(long i=1;i<=n-1;i++)
      dp[i][i+1]=dim[i-1]*dim[i]*dim[i+1];
    for(long d=3;d<=n;d++)
    {
      for(long i=1;i<=n-d+1;i++)
      {
        long minimum = INF;
        long j = i+d-1;
        for(long k=i;k<=j-1;k++)
        {
          long cost = dp[i][k];
          cost+=dp[k+1][j];
          cost+=dim[i-1]*dim[k]*dim[j];
          minimum = min(minimum,cost);
        }
        dp[i][j]=minimum;
      }
    }
    cout<<dp[1][n]<<"\n";

  }
  return 0;
}
