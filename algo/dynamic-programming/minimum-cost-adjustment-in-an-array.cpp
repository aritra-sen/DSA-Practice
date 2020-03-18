#include<iostream>
#include<climits>
using namespace std;
#define MAX_VAL 100

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)  cin>>a[i];
    int target;
    cin>>target;
    int ans[n][MAX_VAL+1];
    for(int j=0;j<=MAX_VAL;j++)
      ans[0][j]=abs(j-a[0]);
    for(int i=1;i<n;i++)
    {
      for(int j=0;j<=MAX_VAL;j++)
      {
        ans[i][j] = INT_MAX;
        for(int k = max(0,j-target);k<=min(MAX_VAL,j+target);k++)
        {
          ans[i][j] = min(ans[i][j],dp[i-1][k]+abs(j-a[i]));
        }
      }
    }
    int result = INT_MAX;
    for(int i=0;i<=MAX_VAL;i++)
      result = min(result,ans[n-1][i]);
    cout<<result<<"\n";
  }
  return 0;
}
