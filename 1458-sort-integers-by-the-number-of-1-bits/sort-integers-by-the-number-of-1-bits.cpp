class Solution {
public:



    vector<int> sortByBits(vector<int>& arr) {
        auto lambda=[&](int &a,int &b){
             int counta=__builtin_popcount(a);
             int countb=__builtin_popcount(b);

            if(counta==countb){
                return a<b;
            }
            return counta<countb;
        };
        sort(begin(arr),end(arr),lambda);
        return arr;
        
    }
};