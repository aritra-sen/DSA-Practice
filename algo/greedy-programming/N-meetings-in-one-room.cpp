#include<iostream>
#include<algorithm>
using namespace std;

class Meeting
{
  public:
  int start;
  int end;
  int index;
  Meeting(int s,int e,int i)
  {
      this->start = s;
      this->end = e;
      this->index = i;
  }
  Meeting()
  {
      start = -1;
      end = -1;
      index = -1;
  }
};

bool comp(const Meeting &x,const Meeting &y)
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
    Meeting m[n];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        m[i]=Meeting(x,-1,i+1);
    }
    for(int i=0;i<n;i++)
      cin>>m[i].end;
    sort(m,m+n,comp);
    int start = 0;
    cout<<m[0].index<<" ";
    for(int i=1;i<n;i++)
    {
      if(m[i].start > m[start].end)
      {
        cout<<m[i].index<<" ";
        start =i;
      }
    }
    cout<<"\n";
  }
  return 0;
}
