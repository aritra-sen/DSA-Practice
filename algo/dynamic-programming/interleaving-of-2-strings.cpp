#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string a,b,c;
    cin>>a>>b>>c;
    if(a.size()+b.size() != c.size())
    {
      cout<<"0\n";
      continue;
    }
    bool dp[a.size()+1][b.size()+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=a.size();i++)
    {
      for(int j=0;j<=b.size();j++)
      {
        if(i==0 && j==0)
          dp[i][j] = 1;
        else if(i==0)
        {
          if(b[j-1]==c[j-1])
            dp[i][j] = dp[i][j-1];
        }
        else if(j==0)
        {
          if(a[i-1]==c[i-1])
            dp[i][j] = dp[i-1][j];
        }
        else if(a[i-1]==c[i+j-1] && b[j-1]!=c[i+j-1])
          dp[i][j] = dp[i-1][j];
        else if(a[i-1]!=c[i+j-1] && b[j-1]==c[i+j-1])
          dp[i][j] = dp[i][j-1];
        else if(a[i-1]==c[i+j-1] && b[j-1]==c[i+j-1])
          dp[i][j] = dp[i-1][j]||dp[i][j-1];
      }
    }
    cout<<dp[a.size()][b.size()]<<"\n";
  }
  return 0;
}
