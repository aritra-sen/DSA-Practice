#include<iostream>
#include<algorithm>
using namespace std;

class Activity
{
  public:
  int start;
  int end;
  int index;
  Activity(int s,int e,int i)
  {
      this->start = s;
      this->end = e;
      this->index = i;
  }
  Activity()
  {
      start = -1;
      end = -1;
      index = -1;
  }
};

bool comp(const Activity &x,const Activity &y)
{
    return x.end<y.end;
}

int main()
{
  int  t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    Activity m[n];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        m[i]=Activity(x,-1,i+1);
    }
    for(int i=0;i<n;i++)
      cin>>m[i].end;
    sort(m,m+n,comp);
    int start = 0,count = 1;
    for(int i=1;i<n;i++)
    {
      if(m[i].start >= m[start].end)
      {
        count++;
        start =i;
      }
    }
    cout<<count<<"\n";
  }
  return 0;
}
