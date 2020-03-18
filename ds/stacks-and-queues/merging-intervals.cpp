#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    pair<int,int> a[n];
    for(int i=0;i<n;i++)
    {
      int x,y;
      cin>>x>>y;
      a[i] = {x,y};
    }
    sort(a,a+n);
    int index = 0;
    for(int i=1;i<n;i++)
    {
      pair<int,int> curr = a[i],prev = a[index];
      if(curr.first > prev.second)
      {
          index++;
          a[index] = a[i];
      }
      else
      {
          a[index].second = max(a[index].second,a[i].second);
          a[index].first = min(a[index].first,a[i].first);
      }
    }
    for(int i=0;i<=index;i++)
      cout<<a[i].first<<" "<<a[i].second<<" ";
    cout<<"\n";
  }
  return 0;
}
