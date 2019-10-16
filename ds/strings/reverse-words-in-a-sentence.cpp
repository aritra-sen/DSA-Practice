#include <iostream>
using namespace std;

int main() {
    int  t;
    cin>>t;
    while(t--)
    {
        string x;
        cin>>x;
        string n="",ans="";
        for(int i=x.size()-1;i>=0;i--)
        {
            if(x[i]==' ')
            {
                int s = 0, e = n.size()-1;
                while(s<e)
                    swap(n[s++],n[e--]);
                ans+=n;
                ans+=" ";
                n="";
            }
            else
                n+=x[i];
        }
        int s = 0, e = n.size()-1;
        while(s<e)
            swap(n[s++],n[e--]);
        ans+=n;
        cout<<ans<<"\n";
    }
	return 0;
}
