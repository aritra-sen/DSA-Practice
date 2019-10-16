#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int arr[],int s,int e)
{
  srand(time(0));
  int random_pivot = s + rand()%(e-s+1);
  swap(arr[s],arr[random_pivot]);
  int pivot = arr[s];
  int j = s;
  for(int i=s+1;i<=e;i++)
  {
    if(arr[i]<pivot)
    {
      j++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[j],arr[s]);
  return j;
}

void quicksort(int arr[],int s,int e)
{
  if(s<e)
  {
    int pivot = partition(arr,s,e);
    quicksort(arr,s,pivot-1);
    quicksort(arr,pivot+1,e);
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
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
  }
  return 0;
}
