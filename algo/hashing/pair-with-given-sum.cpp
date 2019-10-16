#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,sum;
    cin>>n>>sum;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      map[x]++;
    }
    int num_of_pairs = 0;
    unordered_map<int,int>::iterator it = map.begin();
    for(;it!=map.end();++it)
    {
      int n1 = it->first;
      int n2 = sum - n1;
      if(n1==n2)
        if(map[n1]>=2)
          num_of_pairs += (map[n1]*(map[n1]-1))/2;
      else
        num_of_pairs += map[n1]*map[n2];
    }
    cout<<num_of_pairs<<"\n";
  }
  return 0;
}
