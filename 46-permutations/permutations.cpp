// class Solution {

// private:
// void solve(vector<int>nums,vector<vector<int>>&ans,int index){
//     if(index>=nums.size()){
//         ans.push_back(nums);
//         return;
//     }
//     for(int j=index;j<nums.size();j++){
//         swap(nums[index],nums[j]);
//         solve(nums,ans,index+1);
//         swap(nums[index],nums[j]);
//     }
// }   
// public:

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>ans;
//         int index=0;
//         solve(nums,ans,index);
//         return ans;

        
//     }
// };
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int index){
        if(index==nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};