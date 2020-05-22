# To arrange the list in such a manner that the list is sorted in decreasing order of salary.
# And if two employees have the same salary,
# they should be arranged in lexicographical manner such that the list contains only names of those employees having salary greater than or equal to a given number x.


################################################## implementations #####################################################################


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool com(pair<string,int> p,pair<string,int> p1)
{
	if(p.second !=p1.second)
	  return(p.second>p1.second);
    else 
	   return(p.first<p1.first);	  
}
int main() {
	int k;
	cin>>k;
	vector<pair<string,int>> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string name;
		int sal;
		cin>>name >>sal;
		if(sal>=k)
		v.push_back(make_pair(name,sal));
	}
	sort(v.begin(),v.end(),com);
	for(auto it:v)
	 cout<<it.first<<" "<<it.second<<endl;
	return 0;
}
