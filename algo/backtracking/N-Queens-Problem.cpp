#include<iostream>
using namespace std;
#define MAX 10

bool isSafe(bool vis[MAX][MAX],int r,int c,int n)
{
  for(int i=0;i<n;i++)
    if(vis[r][i])
      return false;
  for(int i=r,j=c;j>=0 && i<n;j--,i++)
    if(vis[i][j])
      return false;
  for(int i=r,j=c;i>=0 && j>=0;i--,j--)
    if(vis[i][j])
      return false;
  return true;
}

void nQueen(bool vis[MAX][MAX],int n,int c)
{
  if(c==n)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        cout<<(vis[i][j]?"Q":"-")<<" ";
      cout<<"\n";
    }
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      if(isSafe(vis,i,c,n))
      {
        vis[i][c]=true;
        nQueen(vis,n,c+1);
        vis[i][c]=false;
      }
    }
  }
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    bool vis[MAX][MAX];
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        vis[i][j]=false;
    nQueen(vis,n,0);
  }
  return 0;
}
