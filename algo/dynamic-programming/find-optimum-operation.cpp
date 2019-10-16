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
    int dp[n+1]={0};
    for(int i=1;i<=n;i++)
    {
      if(i%2 == 0)
        dp[i]=min(dp[i/2],dp[i-1])+1;
      else
        dp[i]=dp[i-1]+1;
    }
    cout<<dp[n]<<"\n";
  }
  return 0;
}
