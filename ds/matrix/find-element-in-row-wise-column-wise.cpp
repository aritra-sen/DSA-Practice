#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n,key;
    cin>>m>>n>>key;
    int mat[m][n];
    for(int i=0;i<m;i++)
      for(int j=0;j<m;j++)
        cin>>mat[i][j];
    int i = 0 , j = n-1;
    bool flag = false;
    while(i<m && j>=0)
    {
      if(mat[i][j]<key)
        i++;
      else if(mat[i][j]>key)
        j--;
      else
      {
        cout<<i<<" "<<j<<"\n";
        flag =  true;
        break;
      }
    }
    if(!flag)
      cout<<"-1\n";
  }
  return 0;
}
