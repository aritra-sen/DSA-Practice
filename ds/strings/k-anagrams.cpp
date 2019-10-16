#include<iostream>
using namespace std;

bool areKAnagrams(string str1, string str2, int k)
{
    if(str1.size()!=str2.size())
        return false;
    int s1[26]={0},s2[26]={0};
    int diff = 0;
    for(int i=0;i<str1.size();i++)
    {
        s1[str1[i]-'a']++;
        s2[str2[i]-'a']++;
    }
    for(int i=0;i<26;i++)
        diff+=abs(s1[i]-s2[i]);
    if(diff<=2*k)
        return true;
    return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		if (areKAnagrams(str1, str2, k))
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
return 0;
}
