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
    int lis[n];
    int lds[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        lis[i]=1;
        lds[i]=1;
    }
    for(int i=1;i<n;i++)
    {
      for(int j=0;j<i;j++)
      {
        if(a[i]>a[j] && lis[i]<lis[j]+1)
          lis[i]=lis[j]+1;
      }
    }
    for(int i=n-2;i>=0;i--)
    {
      for(int j=i+1;j<n;j++)
      {
        if(a[i]>a[j] && lds[i]<lds[j]+1)
          lds[i]=lds[j]+1;
      }
    }
    int ans = 1;
    for(int i=0;i<n;i++)
      ans = max(lis[i]+lds[i]-1,ans);
    cout<<ans<<"\n";
  }
  return 0;
}
