#include <iostream>
using namespace std;

int main() {
    long ugly[10001];
    ugly[0]=1;
    int i2=0,i3=0,i5=0;
    long next_2 = 2,next_3 = 3,next_5 = 5;
    for(int i=1;i<10001;i++)
    {
        long next = min(next_2,min(next_3,next_5));
        if(next == next_2)
        {
            i2++;
            ugly[i]=next_2;
            next_2 = ugly[i2]*2;
        }
        if(next == next_3)
        {
            i3++;
            ugly[i]=next_3;
            next_3 = ugly[i3]*3;
        }
        if(next == next_5)
        {
            i5++;
            ugly[i]=next_5;
            next_5 = ugly[i5]*5;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ugly[n-1]<<"\n";
    }
	return 0;
}
