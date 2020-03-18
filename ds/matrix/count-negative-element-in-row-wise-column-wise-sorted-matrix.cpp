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
      for(int j=0;j<m;j++)
        cin>>mat[i][j];
    int i = 0 , j = n-1;
    int ans = 0;
    while(i<m && j>=0)
    {
      if(mat[i][j]<0)
      {
        ans+=j+1;
        i++;
      }
      else
        j--;
    }
    cout<<ans<<"\n";
  }
  return 0;
}
