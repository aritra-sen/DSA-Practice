#include<iostream>
using namespace std;


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n,k,start_x,start_y;
    cin>>m>>n>>start_x>>start_y>>k;
    int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    double dp[m][n][k+1];

    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        dp[i][j][0]=1.0;

    for(int steps = 1;step<=k;steps++)
    {
      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++)
        {
          dp[i][j][steps]=0;
          for(int dir = 0;dir<4;dir++)
          {
            int x = i + d[dir][0];
            int y = j + d[dir][1];
            if(x>=0 && x<m && y>=0 && y<n)
              dp[i][j][steps]+=0.25*dp[x][y][steps-1];
          }
        }
      }
    }
    cout<<dp[start_x][start_y][k]<<"\n";
  }
  return 0;
}
