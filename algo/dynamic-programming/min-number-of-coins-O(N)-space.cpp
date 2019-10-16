#include <iostream>
#include <climits>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int types = 10;
	    int val[] ={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	    int sol[n+1]={0};
      sol[0]=0;
	    for(int i=1;i<=n;i++)
	    {
          sol[i]= INT_MAX;
          for(int j=0;j<types;j++)
	        {
	          if(val[j]<=i)
	             sol[i] = min(sol[i],1 + sol[i-val[j]]);
	        }
	    }
	    cout<<sol[n]<<"\n";
	}
	return 0;
}
