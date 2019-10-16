#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    int a[n],b[m],c[n+m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int p1 = 0,p2 = 0, i = 0;
    while(p1<n && p2<m)
    {
      if(a[p1]<b[p2])
        c[i++]=a[p1++];
      else
        c[i++]=b[p2++];
    }
    while(p1<n)
      c[i++]=a[p1++];
    while(p2<m)
      c[i++]=b[p2++];
    for(int z=0;z<i;z++)
      cout<<c[z]<<" ";
    cout<<"\n";
  }
  return 0;
}
