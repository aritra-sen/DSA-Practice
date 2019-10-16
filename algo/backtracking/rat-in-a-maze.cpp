#include <iostream>
#include <vector>
using namespace std;
#define MAX 100

vector<string> sol;
int d[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
string dir="DLRU";

bool isSafe(int m[MAX][MAX],int n,int i,int j)
{
    return (i>=0 && i<n && j>=0 && j<n && m[i][j]);
}

void solve(int m[MAX][MAX],int n,int r,int c,string &ans)
{
    if(r==n-1 && c==n-1)
    {
        sol.push_back(ans);
        return;
    }
    m[r][c]=0;
    for(int i=0;i<=3;i++)
    {
        int x = r + d[i][0];
        int y = c + d[i][1];
        if(isSafe(m,n,x,y))
        {
            ans+=dir[i];
            solve(m,n,x,y,ans);
            ans.pop_back();
        }
    }
    m[r][c]=1;
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    return sol;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;

	int m[100][100];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>m[i][j];

  sol.clear();
  string x = "";
  solve(m,n,0,0,x);
  for(int i=0;i<sol.size();i++)
	   cout<<sol[i]<<" ";
	cout<<endl;
}
	return 0;
}
