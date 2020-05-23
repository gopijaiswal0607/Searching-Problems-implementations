# You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.

######################################### CODE #######################################################################

# Using binary search
#include<iostream>
using namespace std;
#define ll unsigned long long int
ll K_root(ll number,ll k)
{
	ll Ans=number;
	ll s=0,e=number;
	int flag=0;
	if (k==1)
	 Ans=number;
	else 
	while(s<=e)
	{   ll temp=1;
		ll mid=(s+e)/2;
	     for(ll i=0;i<k;i++){
		     temp=temp*mid;
			 flag=1;
			if(temp>number)
			{
				flag=0;
				e=mid-1;
			break;
			}}
			if( temp<=number && flag==1){
			  Ans=mid;
			  s=mid+1;}
	}
	return Ans;

}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		ll  N,k;
		cin>>N>>k;
		cout<<K_root(N,k)<<endl;
	}

	return 0;
}

