#include<iostream>
#include<algorithm>
using namespace std;


//Method2 --> using 2 pointers
long solve2(int arr[],int n)
{
  long long ans = 0;
  sort(arr,arr+n);
  for(int i = n-1;i>=0;i--)
  {
    int j=i-1,k=0;
    while(k<j)
    {
      if(arr[i]==(arr[k]+arr[j]))
      {
        ans++;
        k++;
        j--;
      }
      else if(arr[i]<(arr[k]+arr[j]))
        j--;
      else
        k++;
    }
  }
  return ans;
}

//Method1 --> Using Hash Function
//Not include here : case for 0 + 0 = 0 and 0 + x = x
long solve1(int arr[],int n)
{
  int hash[1000001]={0};
  for(int i=0;i<n;i++)
    hash[arr[i]]++;
  long ans = 0;
  for(int i=1;i<=(1e6)/2;i++)
    ans+=hash[2*i]*(hash[i]*(hash[i]-1))/2;
  for(int i=1;i<=(1e6);i++)
    for(int j=i+1;j<=(1e6);j++)
      ans+=hash[i]*hash[j]*hash[i+j];
  return ans;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    long ans = solve2(a,n);
    if(ans==0)
      cout<<"-1\n";
    else
      cout<<ans<<"\n";
  }
  return 0;
}
