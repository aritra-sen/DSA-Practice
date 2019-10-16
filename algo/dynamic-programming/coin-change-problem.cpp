#include<iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
    int n,val;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++) cin>>coins[i];
    cin>>val;
    int sol[val+1]={0};
    sol[0]=1;
    for(int j=0;j<n;j++)
    {
      for(int i=1;i<=val;i++)
      {
	       if(coins[j]<=i)
          sol[i]+=sol[i-coins[j]];
      }
	  }
	  cout<<sol[val]<<"\n";
	}
	return 0;
}
