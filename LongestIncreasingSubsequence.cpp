// Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence .The longest increasing subsequence means to find a subsequence of a given sequence in which the 
// subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.
Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3

#include<bits/stdc++.h>
using namespace std;
int lis(int a[],int n)
{
    int i,j;
    int dp[n];
    dp[0]=1;
    for(i=1;i<n;i++)
    {
        dp[i]=1;
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>=a[i])
            continue;
            int temp=dp[j]+1;
            if(temp>dp[i])
            dp[i]=temp;
        }
    }
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(dp[i]>ans)
        ans=dp[i];
    }
    return ans;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int i,a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    cout<<lis(a,n)<<"\n";
	}
	return 0;
}
