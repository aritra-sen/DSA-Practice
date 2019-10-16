#include<iostream>
#include<queue>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    while(n--)
    {
      int x;
      cin>>x;
      int s1 = minHeap.size();
      int s2 = maxHeap.size();
      if(s2==s1)
      {
        int effective_median = maxHeap.top()+minHeap.top();
        effective_median/=2;
        if(x<effective_median)
          maxHeap.push(x);
        else
          minHeap.push(x);
      }
      else if(s2>s1)
      {
        int effective_median = maxHeap.top();
        if(x<effective_median)
        {
          minHeap.push(maxHeap.top());
          maxHeap.pop();
          maxHeap.push(x);
        }
        else
          minHeap.push(x);
      }
      else
      {
        int effective_median = minHeap.top();
        if(x>effective_median)
        {
          maxHeap.push(minHeap.top());
          minHeap.pop();
          minHeap.push(x);
        }
        else
          maxHeap.push(x);
      }
      s1 = minHeap.size();
      s2 = maxHeap.size();
      if(s1==s2)
        cout<<(maxHeap.top()+minHeap.top())/2.0<<"\n";
      else if(s1>s2)
        cout<<minHeap.top()<<"\n";
      else
        cout<<maxHeap.top()<<"\n";
    }
  }
  return 0;
}
