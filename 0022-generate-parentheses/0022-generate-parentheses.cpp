class Solution {
public:
    vector<string> generateParenthesis(int n) { 
         vector<string> ans;
         dfs(0, 0 , ans, "", n);
         return ans;
    }

    void dfs(int left, int right, vector<string>& ans, string s, int n){
        if(s.length() == 2 * n){
            ans.push_back(s);
            return;
        }
        if(left < n) dfs(left + 1, right, ans, s + "(", n);
        if(right < left) dfs(left, right + 1, ans, s + ")", n);
    }
};