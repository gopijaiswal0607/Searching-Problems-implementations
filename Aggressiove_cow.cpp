#Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
#The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).

#His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
#To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
## Input Format
# First line contains N and C, separated by a single space, representing the total number of stalls and number of cows respectively. 
#The next line contains N integers containing the indexes of stalls.

#  Output Format
#  Print one integer: the largest minimum distance.
###################################################### Implementations ##########################################################


#include<iostream>
#include<algorithm>
using namespace std;
bool MinDistance(int stall[],int No_of_stall,int cows,int min_sep)
{  
int Last_cow=stall[0];
int count=1;
for(int i=1;i<No_of_stall;i++)
{
   if(stall[i]-Last_cow>=min_sep)
   {
	   Last_cow=stall[i];
	    count++;
		if(count==cows)
		  return true;
   }
}
return false;
	}
int main() {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	sort(arr,arr+n);
	int s=0,e=arr[n-1]-arr[0];
	int ans=0;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(MinDistance(arr,n,k,mid))
		{
			ans=mid;
			s=mid+1;
		}
		else
		  e=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
