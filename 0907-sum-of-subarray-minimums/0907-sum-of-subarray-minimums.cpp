class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        long long mod = 1e9 + 7;
        stack<int> st;
        for(int i = 0 ; i <= n; i++){
            int curr = (i == n ? 0 : arr[i]);
            while(!st.empty() && arr[st.top()] > curr){
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long l = mid - left;
                long long r = right - mid;
                long long prod = arr[mid] * l * r;

                ans = (ans + prod) % mod;
            }
            if(i < n){
                st.push(i);
            }
        }
        return ans;
    }
};