#include <iostream>
using namespace std;

int power(int x,int y,int M)
{
    if(y==0)
        return 1;
    else if(y==1)
        return x%M;
    else if(y & 1)
        return (x%M*power(x,y-1,M)%M)%M;
    else
    {
        int a = power(x,y/2,M)%M;
        return (a*a)%M;
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int x,y,M;
	    cin>>x>>y>>M;
	    cout<<power(x,y,M)<<"\n";
	}
	return 0;
}
