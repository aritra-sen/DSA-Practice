#include<iostream>
using namespace std;


long merge(long arr[],long l,long mid,long r,long sorted[])
{
  long i=l,j=mid+1,k=l;
  long count = 0;
  while(i<=mid && j<=r)
  {
    if(arr[i]<=arr[j])
      sorted[k++]=arr[i++];
    else
    {
      sorted[k++]=arr[j++];
      count+=(mid-i+1);
    }
  }
  while(i<=mid)
    sorted[k++]=arr[i++];
  while(j<=r)
    sorted[k++]=arr[j++];
  for(long i=l;i<=r;i++)
    arr[i]=sorted[i];
  return count;
}

long mergesort(long arr[],long l,long r,long sorted[])
{
  long count = 0;
  if(l<r)
  {
    long mid = l + (r-l)/2;
    count += mergesort(arr,l,mid,sorted);
    count += mergesort(arr,mid+1,r,sorted);
    count += merge(arr,l,mid,r,sorted);
  }
  return count;
}

long inversion(long arr[],long n)
{
  long sorted[n];
  return mergesort(arr,0,n-1,sorted);
}


int main()
{
  long t;
  cin>>t;
  while(t--)
  {
    long n;
    cin>>n;
    long a[n];
    for(long i=0;i<n;i++) cin>>a[i];
    long ans = inversion(a,n);
    cout<<ans<<"\n";
  }
  return 0;
}
