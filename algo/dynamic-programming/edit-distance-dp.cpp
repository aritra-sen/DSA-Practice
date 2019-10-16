#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    string x,y;
    cin>>x>>y;
    int dist[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
      for(int j=0;j<=m;j++)
      {
        if(i==0)
          dist[i][j]=j;
        else if(j==0)
          dist[i][j]=i;
        else if(x[i-1]==y[j-1])
          dist[i][j]=dist[i-1][j-1];
        else
        {
          dist[i][j]=min(min(dist[i-1][j],dist[i][j-1]),dist[i-1][j-1]) + 1;
        }
      }
    }
    cout<<dist[n][m]<<"\n";
  }
  return 0;
}
