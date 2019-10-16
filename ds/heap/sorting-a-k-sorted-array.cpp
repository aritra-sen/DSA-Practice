#include<iostream>
#include<queue>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<k && i<n;i++)
      minHeap.push(a[i]);
    for(int i=0;i<n;i++)
    {
      a[i]=minHeap.top();
      minHeap.pop();
      if(i+k-1<n)
        minHeap.push(a[i+k-1]);
    }
  }
  return 0;
}
