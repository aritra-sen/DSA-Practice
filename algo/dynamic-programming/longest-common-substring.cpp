#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    int lcs[n+1][m+1];
    int ans = 0;
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=m;j++)
      {
        if(i==0||j==0)
          lcs[i][j]=0;
        else if(a[i-1]==b[j-1])
        {
          lcs[i][j]=lcs[i-1][j-1]+1;
          ans = max(ans,lcs[i][j]);
        }
        else
          lcs[i][j]=0;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
