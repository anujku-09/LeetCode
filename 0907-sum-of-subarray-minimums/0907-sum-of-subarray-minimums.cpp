class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        long long mod = 1e9 + 7;
        vector<int>res1(n);
        vector<int>res2(n);
        stack<int> st1, st2;
        for(int i = 0 ; i < n; i++){
            while(!st1.empty() && arr[st1.top()] > arr[i]){
                st1.pop();
            }
            if(st1.empty()){
                res1[i] = -1;
            }
            else{
                res1[i]= st1.top();
            }
            st1.push(i);
        }
        for(int i = n - 1; i >= 0; i--){
            while(!st2.empty() && arr[st2.top()] >= arr[i]){
                st2.pop();
            }
            if(st2.empty()){
                res2[i]= n;
            }
            else{
                res2[i] = st2.top();
            }
            st2.push(i);
        }
        for(int i = 0; i < n; i++){
            long long left = i - res1[i];
            long long right = res2[i] - i;
            long long total_subarrays = (left * right) % mod;
            ans = (ans + (long long)arr[i] * total_subarrays) % mod;
        }
        return ans;
    }
};