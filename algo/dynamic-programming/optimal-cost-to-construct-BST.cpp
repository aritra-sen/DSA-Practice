#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

unordered_map<string,int> m;

int solve(int freq[],int l, int r, int level)
{
  if(l>r)
    return 0;
  string key = to_string(l) + "|" + to_string(r) + "|" + to_string(level);
  if(m.find(key)!=m.end())
    return m[key];
  int ans = INT_MAX;
  for(int i = l; i<=r; i++)
    ans = min(ans,level*freq[i] + solve(freq,l,i-1,level+1)+solve(freq,i+1,r,level+1));
  return (m[key] = ans);

}


int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int freq[n];
    for(int i=0;i<n;i++)
      cin>>freq[i];
    int ans = solve(freq,0,n-1,1);
    cout<<ans<<"\n";
  }
  return 0;
}
