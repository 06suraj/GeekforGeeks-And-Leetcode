class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string temp="";
	    for(int i=0;i<nums.size();i++)temp+='1';
	    set<string>se;
	    for(int i=0;i<nums.size();i++){
	        string s=nums[i];
	        se.insert(s);
	    }
	    if(se.find(temp)==se.end())return temp;
	    else{
	        int flag=0;
	        for(int i=0;i<nums.size();i++){
	            temp[i]='0';
	             if(se.find(temp)==se.end()){
	                 flag=1;
	                 break;
	             }
	            
	        }
	        if(flag)return temp;
	        else{
	            temp[0]='1';
                return temp;
	        }
	    }
        
    }
};
