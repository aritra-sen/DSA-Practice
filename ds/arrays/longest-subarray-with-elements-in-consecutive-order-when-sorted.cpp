#include<iostream>
using namespace  std;

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
    for(int i=0;i<n;i++)
    {
      bool vis[100001] = {false};
      vis[a[i]]=true;
      int maxInRange = a[i],minInRange=a[i];
      for(int j=i+1;j<n;j++)
      {
        if(vis[a[j]])
          break;
        maxInRange = max(maxInRange,a[j]);
        minInRange = max(minInRange,a[j]);
        if(maxInRange - minInRange == j-i)
          ans = max(ans,j-i+1);
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
