#include<iostream>
using namespace std;

int lcs(string a,string b,int n,int m)
{
  if(n==0||m==0)
    return 0;
  else
  {
    if(a[n-1]==b[m-1])
      return lcs(a,b,n-1,m-1)+1;
    else
      return max(lcs(a,b,n-1,m)+lcs(a,b,n,m-1));
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
    int ans = lcs(a,b,n,m);
    cout<<ans<<"\n";
  }
  return 0;
}
