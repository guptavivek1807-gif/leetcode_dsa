class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            long long current_val = 1; // Tracks the combination value safely
            
            for (int j = 0; j <= i; j++) {
                row.push_back(current_val);
                
                // Using the math trick to compute the next element in the same row
                // i is the row index, j is the element index
                current_val = current_val * (i - j) / (j + 1);
            }
            
            ans.push_back(row);
        }
        
        return ans;
    }
};