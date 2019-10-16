#include<iostream>
#include<cstdlib>
using namespace std;


int partition(int a[],int l,int r)
{
  srand(time(0));
  int rndm = l + rand()%(r-l+1);
  swap(a[rndm],a[l]);
  int piv_val = a[l];
  int i = l;
  for(int j=l+1;j<=r;j++)
  {
    if(a[j]<piv_val)
    {
      i++;
      swap(a[j],a[i]);
    }
  }
  swap(a[i],a[l]);
  return i;
}

int quickselect(int a[],int n,int k)
{
  int l=0;
  int r=n-1;
  while(l<=r)
  {

    int pivot = partition(a,l,r);
    if(pivot+1 == k)
      return a[pivot];
    else if(pivot + 1 > k)
      r = pivot - 1;
    else
      l = pivot + 1;
  }
  return -1;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,k;
    cin>>k>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<quickselect(a,n,n-k+1)<<"\n";
  }
  return 0;
}
