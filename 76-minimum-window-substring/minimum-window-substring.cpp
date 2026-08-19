class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        //base case
        if(t.length() > n){
            return "";
        }

        unordered_map<char,int> mp;
        
        //store t in map
        for(char &ch : t){
            mp[ch]++;
        }

        int reqcount = t.length();
        int i = 0;
        int j = 0;

        int minwindowsize = INT_MAX;
        int start_i = 0;

        while(j<n){
            char ch = s[j];

            if( mp[ch] > 0){ // if a char has freq > 0 it means we want it
                reqcount--;
            }

            mp[ch]--; // reduce the freq of that char from map

            while(reqcount == 0){
                //start shrinking the window

                int currwindowsize = j-i + 1;

                if(minwindowsize > currwindowsize){
                  minwindowsize = currwindowsize;
                  start_i = i;
                }

                mp[s[i]]++; // increase freq

                if(mp[s[i]] > 0){ // freq > 0
                     reqcount++;
                }
                i++;
            }
            j++;
        }
        return minwindowsize == INT_MAX ? "" : s.substr(start_i,minwindowsize);
    } 
};