#include <iostream>
using namespace std;

int main() {
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    long long a[n],max=-1e7;
    for(int i=0;i<n;i++)
      cin>>a[i];
    max = a[n-1];
    max+=1;
    int s=0,l=n-1;
    for(int i=0;i<n;i++)
    {
      if(i & 1)
        a[i] = a[i] + max*(a[s++]%max);
      else
        a[i] = a[i] + max*(a[l--]%max);
    }
    for(int i=0;i<n;i++)
    {
      a[i]/=max;
      cout<<a[i]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
