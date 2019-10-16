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
    for(int i=0;i<n;i++)  cin>>a[i];
    int sum;
    cin>>sum;
    unordered_map<int,int> m;
    int s=0;
    int ans=-1;
    m[0]=-1;
    for(int i=0;i<n;i++)
    {
      s+=a[i];
      if(m.find(s)==m.end())
        m[s]=i;
      if(m.find(s-sum)!=m.end())
        ans=max(ans,i-m[s-sum]);
    }
    cout<<ans<<"\n";
  }
  return 0;
}
