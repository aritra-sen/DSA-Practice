#include<iostream>
using namespace  std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      string x;
      int n;
      cin>>n;
      cin>>x;
      int dp[n+1]={0};
      dp[0]=1;
      dp[1]=1;
      if(x[0]=='0')
        cout<<"0\n";
      else
      {
        for(int i=2;i<=n;i++)
        {
            if(x[i-1]>'0')
                dp[i]+=dp[i-1];
            if(x[i-2]=='1'||(x[i-2]=='2' && x[i-1]<='6'))
                dp[i]+=dp[i-2];
        }
        cout<<dp[n]<<"\n";
      }
  }
  return 0;
}
