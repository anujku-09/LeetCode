class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0;
        int maxIdx = 0;
        if(n == 1) return 1;
        for(int i = 0; i < n ; i++){
            if(nums[minIdx] > nums[i]) minIdx = i;
            if(nums[maxIdx] < nums[i]) maxIdx = i;
        }
        int a = min(minIdx, maxIdx);
        int b = max(minIdx, maxIdx);

        return min({b + 1, n - a, n - b + a + 1});
    }
};