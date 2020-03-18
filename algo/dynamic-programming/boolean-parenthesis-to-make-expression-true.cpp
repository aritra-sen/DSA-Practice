#include<iostream>
#include<vector>
using namespace std;

int main()
{
  long long t;
  cin>>t;
  while(t--)
  {
    long long n;
    cin>>n;
    string x;
    cin>>x;
    cout<<x<<"\n";
    vector<long long> val;
    vector<char> symbol;
    for(long long i=0;i<n;i++)
    {
      if(x[i]=='T')
        val.push_back(1);
      else if(x[i]=='F')
        val.push_back(0);
      else
        symbol.push_back(x[i]);
    }
    long long len = val.size();
    long long dp_true[len][len];
    long long dp_false[len][len];
    for(long long i=0;i<len;i++)
    {
        dp_false[i][i] = 1-val[i];
        dp_true[i][i] = val[i];
    }
    for(long long k=2;k<=len;k++)
    {
      for(long long i=0;i<=len-k;i++)
      {
        long long j=i+k-1;
        dp_true[i][j]=0;
        dp_false[i][j]=0;
        for(long long mid =i;mid<j;mid++)
        {
          long long p1_t = dp_true[i][mid];
          long long p1_f = dp_false[i][mid];
          long long p2_t = dp_true[mid+1][j];
          long long p2_f = dp_false[mid+1][j];
          long long value_t=0,value_f=0;
          if(symbol[mid]=='&')
          {
              value_t=p1_t * p2_t;
              value_f=p1_f*p2_f + p1_t*p2_f + p1_f*p2_t;
          }
          if(symbol[mid]=='^')
          {
              value_t=p1_t*p2_f + p1_f*p2_t;
              value_f=p1_t*p2_t + p1_f*p2_f;
          }
          if(symbol[mid]=='|')
          {
              value_t=p1_t*p2_t + p1_t*p2_f + p1_f*p2_t;
              value_f=p1_f*p2_f;
          }
          dp_true[i][j]+=value_t;
          dp_false[i][j]+=value_f;
        }
      }
    }
    cout<<dp_true[0][len-1]<<"\n";
  }
  return 0;
}
