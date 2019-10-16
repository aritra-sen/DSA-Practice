#include<iostream>
#include<queue>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    priority_queue<int,vector<int>,greater<int>> pq;
    int n,k;
    cin>>n>>k;
    while(n--)
    {
      int x;
      cin>>x;
      if(pq.size()<k)
        pq.push(x);
      else
      {
        if(x>pq.top())
        {
          pq.pop();
          pq.push(x);
        }
      }

      if(pq.size()==k)
        cout<<pq.top()<<" ";
      else
        cout<<"-1 ";
    }
    cout<<"\n";
  }
  return 0;
}
