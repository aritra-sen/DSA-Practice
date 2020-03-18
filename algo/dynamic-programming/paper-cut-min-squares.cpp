#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,long> m;

long solve(long x,long y)
{
    long min1 = x*y;
    long min2 = x*y;

    if(x==y)
        return 1;
    string key = to_string(x) + "|" + to_string(y);
    if(m.find(key)!=m.end())
        return m[key];
    for(int i=1;i<=x/2;i++)
        min1 = min(min1,solve(i,y)+solve(x-i,y));
    for(int i=1;i<=y/2;i++)
        min2 = min(min2,solve(x,i)+solve(x,y-i));

    m[key] = min(min1,min2);
    return m[key];
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long x,y;
	    cin>>x>>y;
	    long ans = solve(x,y);
	    cout<<ans<<"\n";
	}
	return 0;
}
