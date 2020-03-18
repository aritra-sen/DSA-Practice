#include<iostream>
using namespace std;

int mat[1001][1001];

unordered_map<string,int> memory;

int numberOfPaths(int i,int j,int cost)
{
    if(i==0 && j==0)
      return cost==mat[i][j];
    string key = to_string(i) + "|" + to_string(j) + "|" + to_string(cost);
    if(memory.find(key)==memory.end())
    {
      if(i==0)
        m[key] = numberOfPaths(i,j-1,cost-mat[i][j]);
      else if(j==0)
        m[key] = numberOfPaths(i-1,j,cost-mat[i][j]);
      else
        m[key] = numberOfPaths(i-1,j,cost-mat[i][j]) + numberOfPaths(i,j-1,cost-mat[i][j]);
    }
    return m[key];
}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    memory.clear();
    int m,n,cost;
    cin>>m>>n;
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>mat[i][j];
    cin>>cost;
    int answer = numberOfPaths(n-1,n-1,cost);
    cout<<answer<<"\n";
  }
  return 0;
}
