class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int maxwater=0;
        while(l<r){
            int currh=min(height[l],height[r]);
            int width=r-l;
            int curra=currh*width;

           maxwater=max(maxwater,curra);
            if(height[l]<height[r]){
                l++;
            } else{
                r--;
            }
        }
        return maxwater;
        
    }
};