#include<iostream>
using namespace std;

bool isIsomorphic(string x,string y)
{
  if(x.size()!=y.size())
    return false;

  int c[26];
  bool vis[26];
  for(int i=0;i<26;i++)
  {
      c[i]=-1;
      vis[i]=false;
  }
  int n = x.size();

  for(int i=0;i<n;i++)
  {
    if(c[x[i]-'a']==-1)
    {
      if(vis[y[i]-'a'])
        return false;
      c[x[i]-'a'] = y[i]-'a';
      vis[y[i]-'a'] = true;
    }
    else
    {
      if(c[x[i]-'a']!=(y[i]-'a'))
        return false;
    }
  }
  return true;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string x,y;
    cin>>x>>y;
    if(isIsomorphic(x,y))
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}
