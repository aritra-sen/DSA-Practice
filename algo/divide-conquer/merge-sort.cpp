#include<iostream>
using namespace std;

void merge(int arr[],int s1,int s2,int e)
{
  int temp[e-s1+1];
  int i=s1,j=s2,k=0;
  while(i<s2 && j<=e)
  {
    if(arr[i]<=arr[j])
      temp[k++]=arr[i++];
    else
      temp[k++]=arr[j++];
  }
  while(i<s2)
    temp[k++]=arr[i++];
  while(j<=e)
    temp[k++]=arr[j++];
  k=0;
  for(int ind = s1;ind<=e;ind++)
    arr[ind]=temp[k++];
}

void mergesort(int arr[],int s,int e)
{
  if(s<e)
  {
    int mid =(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,mid+1,e);
  }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
  }
  return 0;
}
