#include<iostream>
using namespace std;

int lcs(string a,string b,int n,int m,int count)
{
  if(n==0||m==0)
    return count;
  else
  {
    if(a[n-1]==b[m-1])
      count = lcs(a,b,n-1,m-1,count+1);
    else
      count = max(count,max(lcs(a,b,n-1,m,0)+lcs(a,b,n,m-1,0)));
    return count;
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
    int ans = lcs(a,b,n,m,0);
    cout<<ans<<"\n";
  }
  return 0;
}
