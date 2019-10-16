#include<iostream>
using namespace std;

int lower_bound(int arr[],int x,int n)
{
    int l = 0;
    int r = n-1;
    while(l<r)
    {
      int mid = l + (r-l)/2;
      if(arr[mid]>=x)
        r=mid;
      else
        l=mid+1;
    }
    return l;
}

int upper_bound(int arr[],int x,int n)
{
    int l = 0;
    int r = n-1;
    while(l<r)
    {
      int mid = l + (r-l)/2;
      if(arr[mid]>x)
        r=mid;
      else
        l=mid+1;
    }
    return l;
}


int main()
{
  int t;
  cin>>t;
  while(t)
  {
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<(upper_bound(a,x,n) - lower_bound(a,x,n))<<"\n";
  }
  return 0;
}
