#include<iostream>
using namespace std;

int solve(int n)
{
  int a[n+1];
  a[0]=1;
  a[1]=1;
  a[2]=2;
  for(int i=3;i<=n;i++)
    a[i]=a[i-1]+a[i-2]+a[i-3];
  return a[n];
}

int main()
{
  int tc;
  cin>>tc;
  while(tc--)
  {
    int n;
    cin>>n;
    cout<<solve(n)<<"\n";
  }
  return 0;
}
