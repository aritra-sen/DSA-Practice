#include<iostream>
using namespace std;

bool areAnagrams(string str1, string str2)
{
    if(str1.size()!=str2.size())
        return false;
    int s1[26]={0},s2[26]={0};
    for(int i=0;i<str1.size();i++)
    {
        s1[str1[i]-'a']++;
        s2[str2[i]-'a']++;
    }
    for(int i=0;i<26;i++)
        if(s1[i]!=s2[i])
          return false;
    return true;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		if (areAnagrams(str1, str2))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
  return 0;
}
