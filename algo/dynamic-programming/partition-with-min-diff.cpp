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
    int a[n],sum = 0;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      sum+=a[i];
    }
    bool isPossible[n+1][sum+1]={false};
    for(int i=0;i<=n;i++)
      isPossible[i][0] = true;
    for(int i=1;i<=sum;i++)
      isPossible[0][i] = false;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=sum;j++)
      {
        if(a[i-1]<=j)
          isPossible[i][j] = isPossible[i-1][j]||isPossible[i-1][j-a[i-1]];
        else
          isPossible[i][j] = isPossible[i-1][j];
      }
    }
    int min = sum;
    for(int i=1;i<=sum;i++)
    {
      if(isPossible[n][i] && min>abs(sum - 2*i))
        min = abs(sum - 2*i);
    }
    cout<<min<<"\n";
  }
  return 0;
}
