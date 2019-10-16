//@Todo : Wrong Solution Got to work on this
/*
#include<iostream>
using namespace std;

int solve(int a1[],int a2[],int n,int m,int k)
{
  int l1=0,r1=n;
  int l2=0,r2=m;
  while(l1<r1 && l2<r2)
  {
    int m1 = (l1+r1)/2;
    int m2 = (l2+r2)/2;
    if(m1+m2<k)
    {
      if(a1[m1]>a2[m2])
        l2=m2+1;
      else
        l1=m1+1;
    }
    else
    if(a1[m1]>a2[m2])
      r1=m1;
    else
      r2=m2;
  }
  if(l1==r1)
    return a2[k];
  else
    return a1[k];
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,k;
    cin>>n>>m>>k;
    int a[n],b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int ans = solve(a,b,n,m,k);
    cout<<ans<<"\n";
  }
  return 0;
}
*/
