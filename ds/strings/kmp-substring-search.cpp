#include<iostream>
using namespace std;

int brute_force(string text,string pat)
{
  int n = text.size();
  int m = pat.size();

  for(int i=0;i<=n-m;i++)
  {
    bool flag = true;
    for(int j=0;j<m;j++)
    {
      if(text[i+j]!=pat[j])
      {
        flag = false;
        break;
      }
    }
    if(flag)
      return i;
  }
  return -1;
}

int KMP(string text,string pat)
{
  int n = text.size();
  int m = pat.size();

  int lps[m];
  lps[0]=0;
  int i = 1,j=0;

  while(i<m)
  {
    if(pat[i]==pat[j])
    {
      j++;
      lps[i]=j;
      i++;
    }
    else
    {
      if(j!=0)
        j = lps[j-1];
      else
      {
        lps[i]=0;
        i++;
      }
    }
  }

  i=0,j=0;
  while(i<n)
  {
    if(pat[j]==text[i])
    {
      i++;
      j++;
    }
    if(j==M) // match found
    {
      return i-j;
      //Continue searching for other matches
      j = lps[j-1];
    }
    else if(i<n && pat[j]!=text[i])
    {
      if(j!=0)
        j=lps[j-1];
      else
        i++;
    }
  }

  return -1;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string text,pattern;
    cin>>text>>pattern;
    cout<<brute_force(text,pattern)<<"\n";
    cout<<KMP(text,pattern)<<"\n";
  }
  return 0;
}
