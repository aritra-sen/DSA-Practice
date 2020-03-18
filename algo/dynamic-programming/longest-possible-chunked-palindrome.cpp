#include<iostream>
using namespace std;

unordered_map<string,int> m;
int solve(string &x,int l, int r)
{
  if(l>r)
    return 0;
  string key = x.substr(l,r-l+1);
  if(m.find(key)!=m.end())
    return m[key];
  int ans = 1;
  for(int len=1;len<=(r-l+1)/2;len++)
  {
    if(x.substr(l,len) == x.substr(r-len+1,len))
      ans = max(ans,2 + solve(x,l+len,r-len));
  }
  m[key] = ans;
  return m[key];
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string x;
    cin>>x;
    m.clear();
    int n = x.size();
    int ans = solve(x,0,n-1);
    cout<<ans<<"\n";
  }
  return 0;
}
