class Solution {
public:
    bool canShip(vector<int>& weights, int cap, int maxDays){
        int days = 1;
        int curr = 0;
        for(int w : weights){
            if(curr + w <= cap){
                curr += w;
            }
            else{
                days++;
                curr = w;
            }
        }
        return days <= maxDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(canShip(weights, mid, days)){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};