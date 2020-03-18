#include <iostream>
using namespace std;

bool isValid(int x,int y)
{
	char keypad[4][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
	return (x>=0 && x<4 && y>=0 && y<3 && keypad[x][y]!='*' && keypad[x][y]!='#');
}

int main() {
	int t;
	cin>>t;
	char keypad[4][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
	int d[5][2] = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n==1 || n==0)
	    {
	        cout<<n*10<<"\n";
	        continue;
	    }
	    long dp[4][3][n+1];
	    for(int i=0;i<4;i++)
	    {
	        for(int j=0;j<3;j++)
	        {
	            if(keypad[i][j]!='*' && keypad[i][j]!='#')
	            {
	                dp[i][j][0] = 0;
	                dp[i][j][1] = 1;
	            }
	        }
	    }

	    for(int k=2;k<=n;k++)
	    {
	        for(int i=0;i<4;i++)
	        {
	            for(int j=0;j<3;j++)
	            {
	                if(keypad[i][j]!='*' && keypad[i][j]!='#')
	                {
	                    dp[i][j][k]=0;
	                    for(int dir = 0;dir < 5; dir++)
	                    {
	                        int x = i + d[dir][0];
	                        int y = j + d[dir][1];
	                        if(isValid(x,y))
	                            dp[i][j][k]+=dp[x][y][k-1];
	                    }
	                }
	            }
	        }
	    }



	    long ans = 0;
	    for(int i=0;i<4;i++)
	        for(int j=0;j<3;j++)
	            if(keypad[i][j]!='*' && keypad[i][j]!='#')
	                ans+=dp[i][j][n];

	    cout<<ans<<"\n";

	}
	return 0;
}
