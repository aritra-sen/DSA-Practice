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
  return x.start < y.start ;
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
    int ans[n]={0};
    for(int i=0;i<n;i++)
    {
      int x,y;
      cin>>x>>y;
      arr[i] = Pair(x,y);
      ans[i]=1;
    }
    //Sort in increasing order of start if reordering is allowed
    sort(arr,arr+n,comp);
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<i;j++)
        if(arr[j].end < arr[i].start && ans[i]<ans[j]+1)
          ans[i]=ans[j]+1;
    }
    int sol = 1;
    for(int i=0;i<n;i++)
      sol = max(sol,ans[i]);
    cout<<sol<<"\n";
  }
  return 0;
}
