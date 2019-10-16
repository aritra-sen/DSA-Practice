#include <iostream>
#include <set>
using namespace std;

set<string> ans;
void  perm(string x,int i,int n)
{
    if(i==n-1)
    {
        if(ans.find(x)==ans.end())
            ans.insert(x);
        return;
    }
    //No Change
    perm(x,i+1,n);
    //Swaping for permutations
    for(int j=i+1;j<=n-1;j++)
    {
        swap(x[i],x[j]);
        perm(x,i+1,n);
        swap(x[i],x[j]);
    }
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ans.clear();
        string x;
        cin>>x;
        perm(x,0,x.size());
        set<string>::iterator it = ans.begin();
        for(;it!=ans.end();++it)
            cout<<*it<<" ";
        cout<<"\n";
    }
    return 0;
}
