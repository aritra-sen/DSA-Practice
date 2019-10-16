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
    int a[n];
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      minHeap.push(a[i]);
    }
    int i=0;
    while(!minHeap.empty())
    {
      a[i++]=minHeap.top();
      minHeap.pop();
    }
  }
  return 0;
}
