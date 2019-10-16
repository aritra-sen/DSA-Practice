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
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = 1;
    for(int i=1;i<n;i++)
    {
      int l = i-1;
      int h = i+1;
      while(l>=0 && h<n && a[l]==a[h])
      {
          if(h-l+1>ans)
            ans=h-l+1;
          l--;
          h++;
      }
      l = i-1;
      h = i;
      while(l>=0 && h<n && a[l]==a[h])
      {
          if(h-l+1>ans)
            ans=h-l+1;
          l--;
          h++;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
