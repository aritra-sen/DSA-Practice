#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    long long x;
    cin>>n>>x;
    long long a[n],curr=0;
    for(int i=0;i<n;i++)  cin>>a[i];
    int start=0,end=-1;
    while(start<n && end<n)
    {
      if(curr<x){
        end++;
        if(end<n)
          curr+=a[end];
      }
      else if(curr>x){
        curr-=a[start];
        start++;
      }
      else{
        cout<<start+1<<" "<<end+1<<"\n";
        break;
      }
    }
    if(start ==n || end==n)
      cout<<"-1\n";
  }
  return 0;
}
