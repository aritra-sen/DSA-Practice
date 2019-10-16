#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    long long x;
    cin>>n>>x;
    int ans = 0,sum = 0;
    unordered_map<int,int> map;
    while(n--)
    {
      int v;
      cin>>v;
      sum+=v;
      if(map.find(sum-x)!=map.end())
        ans+=map[sum-x];
      if(sum==x)
        ans++;
      map[sum]++;
    }
    cout<<ans<<"\n";
  }
  return 0;
}
