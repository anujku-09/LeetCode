class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i <= n; i++){
            int currheight = (i == n ? 0 : heights[i]);
            while(!st.empty() && heights[st.top()] > currheight){
                int mid = st.top();
                st.pop();
                int height = heights[mid];
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            if(i < n)
                st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int ans = 0;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(matrix[r][c] == '1')
                    heights[c]++;
                else
                    heights[c] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};