#include<iostream>
using namespace std;

bool checkMinHeap(int arr[],int n,int i)
{
  if(i<=(n-2)/2)
  {
    int child1 = 2*i + 1;
    int child2 = 2*i + 2;
    if(child1<n && arr[i]>arr[child1])
      return false;
    if(child2<n && arr[i]>arr[child2])
      return false;
    bool v1 = child1<n?checkMinHeap(arr,n,child1):true;
    bool v1 = child2<n?checkMinHeap(arr,n,child2):true;
    return v1 && v2;
  }
  return true;
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
    cout<<(checkMinHeap(a,n,0)?"True":"False")<<"\n";
  }
  return 0;
}
