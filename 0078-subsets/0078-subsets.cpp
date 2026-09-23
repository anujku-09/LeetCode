class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void solve(vector<int>& nums, int idx){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(nums, idx + 1);
        curr.pop_back();
        solve(nums, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};