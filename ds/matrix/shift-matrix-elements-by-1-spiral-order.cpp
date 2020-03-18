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
    int a[m*n];
    int mat[m][n];
    for(int i=0;i<m*n;i++)  cin>>a[i];
    int r=0,c=0,k=0;
    int prev = mat[0][0];
    while(r<m && c<n)
    {
      for(int i=c;i<n;i++)
        swap(mat[r][i],prev);
      r++;
      for(int j=r;j<m;j++)
        swap(mat[j][n-1],prev);
      c--;
      if(r<m)
      {
        for(int i=n-1;i>=c;i--)
          swap(mat[m-1][i],prev);
      }
      if(c<n)
      {
        for(int j=m-1;j>=r;j--)
          swap(mat[j][c],prev);
      }
    }
    mat[0][0] = prev;
    
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
        cout<<mat[i][j]<<" ";
      cout<<"\n";
    }
  }
  return 0;
}
