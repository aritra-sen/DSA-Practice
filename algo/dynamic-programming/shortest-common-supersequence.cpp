#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string x,y;
    cin>>x>>y;
    int n=x.size();
    int m=y.size();
    int lcs[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=m;j++)
      {
        if(i==0||j==0)
          lcs[i][j]=0;
        else if(x[i-1]==y[j-1])
          lcs[i][j]=lcs[i-1][j-1]+1;
        else
          lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
      }
    }
    cout<<(x.size()+y.size()-lcs[n][m])<<"\n";
  }
  return 0;
}
