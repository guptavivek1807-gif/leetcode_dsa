class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest=INT_MAX;
        int largest=INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < smallest) {
                smallest = nums[i];
            }
            if(nums[i] > largest) {
                largest = nums[i];
            }
        }
   // Fix 3: Standard Euclidean algorithm loop to find the GCD of those two numbers
        while(smallest > 0) {
            int temp = largest % smallest;
            largest = smallest;
            smallest = temp;
        }
       
        return largest;
    }
};