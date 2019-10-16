#include<iostream>
using namespace std;
#define MAX 100000

int lcs[MAX+1][MAX+1];

string get_lcs(string a,string b,int n,int m)
{
  if(n==0||m==0)
    return "";
  else if(a[n-1]==b[m-1])
    return get_lcs(a,b,n-1,m-1)+a[n-1];
  else
  {
    if(lcs[n-1][m]>lcs[n][m-1])
      return get_lcs(a,b,n-1,m);
    else
      return get_lcs(a,b,n,m-1);
  }
}

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
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=m;j++)
      {
        if(i==0||j==0)
          lcs[i][j]=0;
        else if(a[i-1]==b[j-1])
          lcs[i][j]=lcs[i-1][j-1]+1;
        else
          lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
      }
    }
    cout<<get_lcs(a,b,n,m)<<"\n";
  }
  return 0;
}
