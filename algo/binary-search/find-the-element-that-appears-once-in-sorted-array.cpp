#include <iostream>
using namespace std;

long long find_element(long long arr[],int n)
{
  int l=0,r=n-1;
  while(l<=r)
  {
    int mid = l + (r-l)/2;
    if(mid & 1)
    {
      if(arr[mid]==arr[mid-1])
        l=mid+1;
      else if(arr[mid]==arr[mid+1])
        r=mid-1;
      else
        return arr[mid];
    }
    else
    {
      if(arr[mid]==arr[mid-1])
        r=mid-1;
      else if(arr[mid]==arr[mid+1])
        l=mid+1;
      else
        return arr[mid];
    }
  }
  return -1;
}

int main() {
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long element = find_element(a,n);
    cout<<element<<"\n";
  }
  return 0;
}
