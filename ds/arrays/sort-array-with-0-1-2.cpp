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
    int zero=0,i=0,two=n-1;
    //This is like Partition in QuickSort
    while(i<=two)
    {
      if(a[i]==0)
        swap(a[i++],a[zero++]);
      else if(a[i]==2)
        swap(a[i],a[two--]);
      else
        i++;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
  }
  return 0;
}
