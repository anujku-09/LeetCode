class Solution {
public:

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int remove = nums.size() - k;
        for (int num : nums) {
            while (!st.empty() &&
                   remove > 0 &&
                   st.back() < num) {
                st.pop_back();
                remove--;
            }
            st.push_back(num);
        }
        st.resize(k);
        return st;
    }

    bool greaterSequence(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == b.size()) return true;
        if (i == a.size()) return false;
        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> result;
        int i = 0;
        int j = 0;
        while (i < a.size() || j < b.size()) {
            if (greaterSequence(a, i, b, j))
                result.push_back(a[i++]);
            else
                result.push_back(b[j++]);
        }
        return result;
    }

    bool greater(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                return a[i] > b[i];
        }
        return false;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> answer;
        int start = max(0, k - (int)nums2.size());
        int end = min(k, (int)nums1.size());

        for (int take1 = start; take1 <= end; take1++) {
            int take2 = k - take1;
            vector<int> a = maxSubsequence(nums1, take1);
            vector<int> b = maxSubsequence(nums2, take2);
            vector<int> candidate = merge(a, b);

            if (answer.empty() || greater(candidate, answer)) {
                answer = candidate;
            }
        }
        return answer;
    }
};