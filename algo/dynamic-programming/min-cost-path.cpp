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
    int dp[m][n];
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
          if(i==0 && j==0)
            dp[i][j]=a[i][j];
          else if(i==0)
            dp[i][j]=a[i][j]+dp[i][j-1];
          else if(j==0)
            dp[i][j]=a[i][j]+dp[i-1][j];
          else
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
      }
    }
    cout<<dp[m-1][n-1]<<"\n";
  }
  return 0;
}
