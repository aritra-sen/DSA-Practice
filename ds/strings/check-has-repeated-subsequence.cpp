#include<iostream>
using namespace std;

bool isPalindrome(string x)
{
  int l = 0,r = x.size()-1;
  while(l<r)
    if(x[l++]!=x[r--])
      return false;
  return true;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string x;
    cin>>x;
    int n = x.size();
    int count[26]={0};
    for(int i=0;i<n;i++)
      count[x[i]-'a']++;
    bool flag = false;
    for(int i=0;i<26;i++)
    {
      if(count[i]>2)
      {
        flag = true;
        break;
      }
    }
    if(flag)
    {
      cout<<"YES\n";
      continue;
    }
    string new_str="";
    for(int i=0;i<n;i++)
    {
      if(count[x[i]-'a']>1)
        new_str+=x[i];
    }
    if(!isPalindrome(new_str))
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}
