#include<iostream>
using namespace  std;

int solve(int n)
{
  if(n==0)
    return 0;
  else
  {
    if(n & 1)
      return solve(n-1)+1;
    else
      return min(solve(n-1),solve(n/2))+1;
  }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int ans = solve(n);
    cout<<ans<<"\n";
  }
  return 0;
}
