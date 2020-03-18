#include<iostream>
using namespace std;

int numberOfPainters(int arr[],int n,int sum)
{
    int count = 1;
    int val = arr[0];
    for(int i=1;i<n;i++)
    {
      if(val+arr[i]>sum)
      {
        count++;
        val=arr[i];
      }
      else
        val+=arr[i];
    }
    return count;
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    int sum,maximum=a[0];
    sum=a[0];
    for(int i=1;i<n;i++)
    {
      sum+=a[i];
      maximum = max(a[i],maximum);
    }
    int low = maximum,high = sum;
    while(low<high)
    {
      int mid = (low+high)/2;
      int req_painters = numberOfPainters(a,n,mid);
      if(req_painters<=k) // here we can have max k partitions
        low = mid;
      else
        high = mid-1;
    }
    cout<<low<<"\n";
  }
  return 0;
}
