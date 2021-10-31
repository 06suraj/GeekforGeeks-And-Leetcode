#include<bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
	   int n,ans=0;cin>>n;int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
	   for(int i=0;i<n;i++){
	       if(arr[i]>i+1+ans)ans+=arr[i]-i-1-ans;
	   }
	   cout<<ans<<endl;
	}
	return 0;
}
