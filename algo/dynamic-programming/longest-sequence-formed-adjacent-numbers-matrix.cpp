//DFS with Memotization
#include<iostream>
using namespace std;

int vis[1001][1001];
int a[1001][1001];
int d[4][2]= {{0,1},{0,-1},{-1,0},{1,0}};
void dfs(int i,int j,int m,int n)
{
  vis[i][j]=1;
  for(int k=0;k<=3;k++)
  {
    int x = i+d[k][0];
    int y = j+d[k][1];
    if(x<m && x>=0 && y<n && y>=0 && a[i][j]-d[x][y]==1)
    {
      if(vis[i][j]==-1)
        dfs(x,y,m,n);
      vis[i][j]=max(vis[i][j],1+vis[x][y]);
    }
  }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cin>>a[i][j];
        vis[i][j]=-1;
      }
    }
    int ans = 1;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(vis[i][j]==-1)
          dfs(i,j,m,n);
        ans = max(ans,vis[i][j]);
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
