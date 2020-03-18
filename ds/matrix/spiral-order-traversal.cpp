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
    int mat[m][n];
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>mat[i][j];

    int i=0,j=0,r=m,c=n;
    while(i<r && j<c)
    {
      for(int x = j; x<c ; x++)
        cout<<mat[i][x]<<" ";
      i++;
      for(int y = i; y<r; y++)
        cout<<mat[y][c-1]<<" ";
      c--;
      if(i<r)
      {
        for(int x = c-1;x>=j;x--)
          cout<<mat[r-1][x]<<" ";
        r--;
      }
      if(j<c)
      {
        for(int y = r-1; y>=i; y--)
          cout<<mat[y][j]<<" ";
        j++;
      }
    }
    cout<<"\n";
  }
  return 0;
}
