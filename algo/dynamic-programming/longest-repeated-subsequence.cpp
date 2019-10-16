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
    string x;
    cin>>x;
    int ans[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=n;j++)
      {
        if(i==0 || j==0)
          ans[i][j]=0;
        else if(x[i-1]==x[j-1] && i!=j)
          ans[i][j]=ans[i-1][j-1]+1;
        else
          ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
      }
    }
    cout<<ans[n][n]<<"\n";
  }
  return 0;
}
