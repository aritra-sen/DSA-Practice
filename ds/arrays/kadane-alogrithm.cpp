#include<iostream>
using namespace  std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    int sum_till_here = a[0];
    int max_sum = a[0];
    for(int i=1;i<n;i++)
    {
      if(sum_till_here < 0)
        sum_till_here = a[i];
      else
        sum_till_here += a[i];

      max_sum = sum_till_here>max_sum?sum_till_here:max_sum;
    }
    cout<<max_sum<<"\n";
  }
  return 0;
}
