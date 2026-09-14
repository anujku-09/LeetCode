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
            st.push(i);
        }
        return maxArea;
    }
};