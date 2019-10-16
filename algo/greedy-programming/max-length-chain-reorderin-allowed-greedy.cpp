#include<iostream>
using namespace std;

class Pair
{
public:
  int start;
  int end;
  Pair(int x,int y)
  {
    this->start = x;
    this->end = y;
  }
}

bool comp(const Pair &x,const Pair &y)
{
  return x.end < y.end ;
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    Pair arr[n];
    for(int i=0;i<n;i++)
    {
      int x,y;
      cin>>x>>y;
      arr[i] = Pair(x,y);
    }
    sort(arr,arr+n,comp);
    int start = 0;
    int count = 1;
    for(int i=1;i<n;i++)
    {
      if(arr[i].start > arr[start].end)
      {
        count++;
        start = i;
      }
    }
    cout<<count<<"\n";
  }
  return 0;
}
