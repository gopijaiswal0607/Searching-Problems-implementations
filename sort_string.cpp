# Sort all the strings ( lexicographically )
#but if a string is present completely as a prefix in another string, then string with longer length should come first. 
#Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.

############################################## Implementations ################################################################




#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(string s,string s1)
{
int len=s.length();
int len1=s1.length();
int i=0;
while(s[i]==s1[i])
{
   i++;
}
if(s[i] && s1[i])
  return s<s1;
if((s[i]=='\0' && s1[i]!='\0')||(s[i]!='\0'  && s1[i]=='\0'))
  return len>len1 ;
}

int main() {
	int n;
	cin>>n;
	vector<string> v;
	v.reserve(1000);
	for(int i=0;i<n;i++){
	string s;
	cin>>s;
	v.push_back(s);
	}
	sort(v.begin(),v.end(),compare);
	for(auto s:v)
	{
		cout<<s<<endl;
	}
	return 0;
}
