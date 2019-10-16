#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int a[n];
  srand(time(0));
  for(int i=0;i<n;i++) cin>>a[i];

  cout<<"Orignal Array : ";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<"\n";

  for(int i=n-1;i>=0;i--)
  {
    int random =  rand()%(i+1);
    swap(a[i],a[random]);
  }

  cout<<"Shuffled Array : ";
  for(int i=0;i<n;i++) cout<<a[i]<<" ";
  cout<<"\n";

  return 0;
}
