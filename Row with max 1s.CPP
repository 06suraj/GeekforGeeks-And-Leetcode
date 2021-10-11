class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int index=-1,maxi=m,j=m;
	    
	   // 1.BINARY SEARCH O(N*LOG(M));
	    for(int i=0;i<n;i++){
	        int lb=lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
	        if(lb<maxi)
	        {
	            maxi=lb;
	            index=i;
	        }
	    }
	    
	   // 2.TWO POINTER O(N+M)
	    for(int i=0;i<n and j>=0;i++){
	      while(arr[i][j]==1)j--;
	       if(m-j>maxi){
	           maxi=m-j;
	           index=i;
	       }
	   
	    }
	    return index;
	}

};
