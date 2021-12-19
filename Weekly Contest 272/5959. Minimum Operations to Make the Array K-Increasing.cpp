class Solution {
public:
    int LongestIncreasingSubsequenceLength(vector<int>& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] <= a[i] && a[i] <= d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}
 
    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size(),ans=0;
        for(int i=0;i<k;i++){
            vector<int>temp;
            for(int j=i;j<n;j=j+k)temp.push_back(arr[j]);
            int l=LongestIncreasingSubsequenceLength(temp);
              ans+=temp.size()-l;
            
        }
        return ans;
    }
};
