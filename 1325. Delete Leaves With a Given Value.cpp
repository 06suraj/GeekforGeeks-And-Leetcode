#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	    int a,b,c,m;cin>>a>>b>>c;
	    vector<long long>usb,ps;
	    cin>>m;
	    for(int i=0;i<m;i++){
	        int x;cin>>x;
	        string s;cin>>s;
	        if(s=="USB")usb.push_back(x);
	        else ps.push_back(x);
	    }
	    sort(usb.begin(),usb.end());
	    sort(ps.begin(),ps.end());
	    int i=0,j=0,cnt=0;
	    long long s=0;
	    while(i<usb.size() and a){s+=usb[i];i++,a--,cnt++;}
	    while(j<ps.size() and b){
	        s+=ps[j];
	        b--,j++,cnt++;
	    }
	    while((i<usb.size() or j<ps.size()) and c){
	        if(i==usb.size()){s+=ps[j];j++;}
	        else if(j==ps.size()){
	            s+=usb[i];
	            i++;
	        }else{
	            if(ps[j]<usb[i]){
	                s+=ps[j];
	                j++;
	            }else{
	                s+=usb[i];
	                i++;
	            }
	        }
	        cnt++;
	        c--;
	    }
	    cout<<cnt<<" "<<s<<endl;
	return 0;
}
