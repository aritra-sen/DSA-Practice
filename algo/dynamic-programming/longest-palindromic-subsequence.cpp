#include<iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string x;
    cin>>x;
    int ans[n][n]={0};
    for(int i=0;i<n;i++)
      ans[i][i]=1;
    for(int i=0;i<n-1;i++)
      if(x[i]==x[i+1])
        ans[i][i+1]=2;
      else
        ans[i][i+1]=1;
    for(int k=3;k<=n;k++)
    {
      for(int i=0;i<=n-k;i++)
      {
        int j=i+k-1;
        if(x[i]==x[j])
          ans[i][j]=2+ans[i+1][j-1];
        else
        {
          ans[i][j]=max(ans[i][j-1],ans[i+1][j]);
        }
      }
    }
    cout<<ans[0][n-1]<<"\n";
  }
  return 0;
}
