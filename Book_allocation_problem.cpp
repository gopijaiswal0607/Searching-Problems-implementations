//You are given number of pages in n different books and m students. 
//The books are arranged in ascending order of number of pages. 
//Every student is assigned to read some consecutive books.
//The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

############################################# Implementations ##############################################################

#include <iostream>
#include<climits>
# define ll long long
using namespace std;
bool isPossible(ll arr[],ll n,ll curr,ll m)
{   ll students=1;
    ll pages_read=0;
  for(ll i=0;i<n;i++){
      if(pages_read+arr[i]>curr) {
         students++;
         pages_read=arr[i];
          if(students>m){
           return false;}
          
      }
        else{
         pages_read +=arr[i];
  }
      
  }
return true;
}
ll findPages(ll arr[],ll n,ll m)
{
   ll Ans=INT_MAX;
    ll sum=0;
   for(ll i=0;i<n;i++)
      sum+=arr[i];
    if(n<m)
      return -1;
     ll s=arr[n-1];
     ll e=sum;
     while(s<=e){
         ll mid=(s+e)/2;
     if(isPossible(arr,n,mid,m)){
         Ans=min(Ans,mid);
         e=mid-1;
     }
     else
        s=mid+1;
     }
return Ans;
}   
int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,m;
	    cin>>n>>m;
	    ll arr[n];
	    for(ll i=0;i<n;i++)
	      cin>>arr[i];
	   cout<<findPages(arr,n,m)<<endl;
	}
	return 0;
}
