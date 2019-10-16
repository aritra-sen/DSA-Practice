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
	    int sol[n+1][types+1]={0};
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=types;j++)
	        {
	            sol[i][j]= i;
	            if(i==0)
	                sol[i][j]=0;
	            else if(j==0)
	                sol[i][j] = INT_MAX;
	            else
	            {
	                if(val[j-1]<=i)
	                    sol[i][j] = min(sol[i][j-1],1 + sol[i-val[j-1]][j]);
	                else
	                    sol[i][j]=sol[i][j-1];
	            }
	        }
	    }
	    cout<<sol[n][types]<<"\n";
	}
	return 0;
}
