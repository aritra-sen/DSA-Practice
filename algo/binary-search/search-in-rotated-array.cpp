#include <iostream>
using namespace std;

int binary_search(int arr[],int l,int r,int k)
{
  while(l<=r)
  {
    int mid = l + (r-l)/2;
    if(arr[mid]<k)
      l=mid+1;
    else if(arr[mid]>k)
      r=mid-1;
    else
      return mid;
  }
  return -1;
}

int pivot(int arr[],int n)
{
  int l=0,r=n-1;
  while(l<r)
  {
    int mid = (l+r)>>1;
    if(arr[mid]<arr[r])
      r=mid;
    else
      l=mid+1;
  }
  return l;
}

int main() {
  int t;
  cin>>t;
  while(t--)
  {
    int n,x;
    cin>>n>>x;
    int a[n],p;
    for(int i=0;i<n;i++) cin>>a[i];
    if(a[0]< a[n-1]) p = 0;
    else
      p=pivot(a,n);
    if(a[n-1]<x)
      cout<<binary_search(a,0,p-1,x);
    else
      cout<<binary_search(a,p,n-1,x);
    cout<<"\n";
  }
	return 0;
}
