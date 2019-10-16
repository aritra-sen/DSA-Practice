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
    int a[n];
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum & 1)
        cout<<"NO\n";
    else
    {
        sum/=2;
        bool isPossible[n+1][sum+1];
        for(int i=0;i<=n;i++)
            isPossible[i][0]=true;
        for(int i=0;i<=sum;i++)
            isPossible[0][i]=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(a[i-1]<=j)
                    isPossible[i][j]=(isPossible[i-1][j]||isPossible[i-1][j-a[i-1]]);
                else
                    isPossible[i][j]=isPossible[i-1][j];
            }
        }
        cout<<(isPossible[n][sum]?"YES":"NO")<<"\n";
    }
  }
  return 0;
}
