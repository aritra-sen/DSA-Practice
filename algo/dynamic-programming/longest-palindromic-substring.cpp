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
    bool ans[n][n]={false};
    int sol = 1;
    for(int i=0;i<n;i++)
      ans[i][i]=true;
    for(int i=0;i<n-1;i++)
    {
      if(x[i]==x[i+1])
        ans[i][i+1]=true;
      else
        ans[i][i+1]=false;
    }
    for(int k=3;k<=n;k++)
    {
      for(int i=0;i<n-k+1;i++)
      {
        int j=i+k-1;
        if(x[i]==x[j] && ans[i+1][j-1]==true)
        {
          ans[i][j]=true;
          sol=k;
        }
      }
    }
    cout<<sol<<"\n";
  }
  return 0;
}
