class Solution {
public:
    int findDays(vector<int> &weights, long long cap) {
        int days = 1;
        long long load = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] + load > cap) {
                days += 1;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return days;
    }

    // Renamed to match LeetCode's expected standard function name
    int shipWithinDays(vector<int>& weights, int days) {
        long long low = *max_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0LL); 
        long long ans = high;

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(findDays(weights, mid) <= days) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};