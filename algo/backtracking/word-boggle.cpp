#include <iostream>
#include <map>
using namespace std;
#define MAX 10

map<string,int> dict;
bool vis[MAX][MAX];
char word[MAX][MAX];
int d[8][2]={{1,0},{0,-1},{0,1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

bool isSafe(int m,int n,int i,int j)
{
    return (i>=0 && i<m && j>=0 && j<n && !vis[i][j]);
}

void solve(int r,int c,int m,int n,int longest,string &curr)
{
    if(curr.size()>=longest)
        return;
    curr+=word[r][c];
    vis[r][c]=true;
    if(dict.find(curr)!=dict.end())
        dict[curr]=2;
    for(int  i=0;i<=7;i++)
    {
        int x = r + d[i][0];
        int y = c + d[i][1];
        if(isSafe(m,n,x,y))
            solve(x,y,m,n,longest,curr);
    }
    curr.pop_back();
    vis[r][c]=false;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    dict.clear();
	    int m,n;
	    cin>>n;
	    int maxlen=0;
	    while(n--)
	    {
	        string x;
	        cin>>x;
	        dict[x]=1;
	        maxlen = max(maxlen,(int)x.size());
	    }
	    cin>>m>>n;
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>word[i][j];
	            vis[i][j]=false;
	        }
	    }

	    string w = "";
	    for(int i=0;i<m;i++)
	        for(int j=0;j<n;j++)
	            solve(i,j,m,n,maxlen,w);
	    map<string,int>::iterator it = dict.begin();
	    bool flag = false;
	    for(;it!=dict.end();++it)
	    {
	        if(it->second == 2)
	        {
	            flag = true;
	            cout<<it->first<<" ";
	        }
	   }
	   if(!flag)
	        cout<<"-1";
	   cout<<"\n";
	}
	return 0;
}
