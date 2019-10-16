#include<iostream>
using namespace std;

int get_median(int a1[],int a2[],int n,int m)
{
  int l=0,r=n;
  int posX,posY;
  while(l<=r)
  {
    posX = (l+r)/2;
    posY = (n+m+1)/2 - posX;
    if(posX ==0 || a1[posX - 1]<=a2[posY])
    {
      if(posY == 0 || a2[posY - 1] <= a1[posX])
        break;
      else
        l=posX+1;
    }
    else
      r=posX-1;
  }
  if((n+m) & 1)
    return max((posX > 0?a1[posX-1]:-1e6),(posY > 0?a2[posY-1]:-1e6));
  else
    return (max((posX > 0?a1[posX-1]:-1e6),(posY > 0?a2[posY-1]:-1e6))+min((posX < n?a1[posX]:1e6),(posY < m?a2[posY]:1e6)))/2;
}



int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int ans = get_median(a,b,n,m);
    cout<<ans<<"\n";
  }
  return 0;
}
