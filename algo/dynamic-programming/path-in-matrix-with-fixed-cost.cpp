//Wrong
/*
#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>a[i][j];
    int cost;
    cin>>cost;
    int sol[m+1][n+1][cost+1]={0};
    for(int i=0;i<=m;i++)
    {
      for(int j=0;j<=n;j++)
      {
        if(i==0 && j==0)
          sol[i][j][a[i][j]]=1;
        else
        {
          for(int k = 0;k<=cost-a[i][j];k++)
          {
            if(i>0)
              sol[i][j][k+a[i][j]]=sol[i-1][j][k]+1;
            if(j>0)
              sol[i][j][k+a[i][j]]=sol[i][j-1][k]+1;
          }
        }
      }
    }
    cout<<sol[m][n][cost]<<"\n";
  }
  return 0;
}
*/
