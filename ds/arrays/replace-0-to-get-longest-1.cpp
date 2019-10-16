#include<iostream>
using namespace std;

int solve(int a[],int n)
{
  int last_zero = -1;
  int curr_zero = 0;
  int zero_ans = 0;
  int ans = -1;
  for(int i = 0;i<n;i++)
  {
    if(a[i]==0)
    {
      curr_zero = i - last_zero;
      last_zero = i;
    }
    else
    {
        curr_zero++;
    }
    if(curr_zero>zero_ans)
    {
      zero_ans=curr_zero;
      ans = last_zero;
    }
  }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int  n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<solve(a,n)<<"\n";
  }
  return 0;
}
