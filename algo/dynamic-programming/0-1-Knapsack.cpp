#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,W;
    cin>>n>>W;
    int val[n],wt[n];
    for(int i=0;i<n;i++) cin>>val[i];
    for(int i=0;i<n;i++) cin>>wt[i];

    int knapsack[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
      for(int w = 0;w<=W;w++)
      {
        if(i==0 || w==0)
          knapsack[i][w]=0;
        else
        {
          if(wt[i-1]<=w)
            knapsack[i][w] = max(knapsack[i-1][w],knapsack[i-1][w-wt[i-1]]+val[i-1]);
          else
            knapsack[i][w] = knapsack[i-1][w];
        }
      }
    }
    cout<<knapsack[n][W]<<"\n";
  }
  return 0;
}
