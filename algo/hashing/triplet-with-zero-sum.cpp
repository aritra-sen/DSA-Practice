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
    cin>>n;
    int a[n];
    unordered_map<int,int> map;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++)
      map[a[i]]++;
    for(int i=0;i<n-1;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        int c=0;
        int req_sum = -(a[i]+a[j]);
        if(a[i]==req_sum)
          c++;
        if(a[j]==req_sum)
          c++;
        if(map[req_sum]>c)
          ans+=(map[req_sum]-c);
      }
    }
    cout<<c<<"\n";
  }
  return 0;
}
