#include<bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
	    int n,flag=0;cin>>n;int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
	    for(int i=0;i<n;i++){
	        flag=0;
	        for(int j=2;j<=i+2;j++){
	            if(arr[i]%j){flag=1;break;}
	        }
	        if(flag==0){
	            flag=2;
	            break;
	        }
	    }
	    if(flag==2)cout<<"NO\n";
	    else cout<<"YES\n";
	}
	return 0;
}
