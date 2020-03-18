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

    int knapsack[W+1]={0};
    for(int i=0;i<n;i++)
        for(int w = 0;w<=W;w++)
            if(wt[i]<=w)
                knapsack[w] = max(knapsack[w],knapsack[w-wt[i]]+val[i]);

    cout<<knapsack[W]<<"\n";
  }
  return 0;
}
