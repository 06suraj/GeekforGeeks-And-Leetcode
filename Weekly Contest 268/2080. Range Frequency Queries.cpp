class RangeFreqQuery {
public:
    vector<int>ori;
    unordered_map< int, vector<int> > store;
    RangeFreqQuery(vector<int>& arr) {
        ori.clear();
        store.clear();
        for(int i:arr)ori.push_back(i);
        for(int i=0;i<arr.size();i++)store[arr[i]].push_back(i+1);
    }
    
    int query(int left, int right, int element) {
        left++,right++;
        int a = lower_bound(store[element].begin(),store[element].end(),left) - store[element].begin();
        int b = upper_bound(store[element].begin(),store[element].end(),right)- store[element].begin();
        return b-a;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
