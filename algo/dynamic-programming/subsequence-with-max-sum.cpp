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
    int a[n];
    int sol[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sol[i]=a[i];
    }
    for(int i=1;i<n;i++)
    {
      for(int j=0;j<i;j++)
      {
        if(a[i]>a[j] && sol[i]<sol[j]+a[i])
          sol[i]=sol[j]+a[i];
      }
    }
    int ans = sol[0];
    for(int i=0;i<n;i++)
      ans = max(sol[i],ans);
    cout<<ans<<"\n";
  }
  return 0;
}
