#include<iostream>
using namespace std;

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
    int zero=0;
    //This is like Partition in QuickSort
    for(int i=0;i<n;i++)
    {
      if(a[i]==0)
      {
        swap(a[i],a[zero]);
        zero++;
      }
    }
  }
  return 0;
}
