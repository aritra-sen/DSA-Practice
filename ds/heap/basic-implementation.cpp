#include<iostream>
using namespace std;

void to_heap(int arr[],int n)
{
  for(int i=(n/2)-1;i>=0;i--)
    heapify_down(arr,n,i);

}

void heapify_up(int arr[],int n)
{
  int i = n-1;
  int parent = (i-1)/2;
  while(i!=0 && arr[parent]<arr[i])
  {
      swap(arr[i],arr[parent]);
      i = parent;
      parent = (i-1)/2;
  }
}

void heapify_down(int arr[],int n,int i=0)
{
  while(i<n)
  {
      int child1 = 2*i + 1;
      int child2 = 2*i + 2;
      if((child1>=n || arr[i]>=arr[child1]) && (child2>=n || childarr[i]>=arr[child2]))
        break;
      int swapper = (child2<n)?(arr[child1]>arr[child2]?child1:child2):child1;
      swap(arr[i],arr[swapper]);
      i = swapper;
  }
}

void push(int arr[],int &n,int x)
{
  arr[n]=x;
  n++;
}

int pop(int arr[],int &n)
{
  int _out=a[0];
  swap(a[0],a[n-1]);
  n--;
  heapify_down(arr,n);
  return _out;
}


int main()
{
  int n;
  cin>>n;     //size of heap
  int a[n];   // array to heapify
  for(int i=0;i<n;i++) cin>>a[i];
  return 0;
}
