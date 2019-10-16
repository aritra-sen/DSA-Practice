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
    int miss = 0;
    for(int i=1;i<n;i++)
    {
      int x;
      cin>>x;
      miss^=(x^i);
    }
    miss^=n;
    cout<<miss<<"\n";
  }
  return 0;
}
