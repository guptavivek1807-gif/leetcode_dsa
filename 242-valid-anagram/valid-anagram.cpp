class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) 
        return false;

    // Initialize a frequency array to store character counts
    int freq[26] = {0};

    // Count frequency of each character in str1
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;  // Increment frequency for each character in str1
    }

    // Decrement frequency for each character in str2
    for (int i = 0; i < t.length(); i++) {
        freq[t[i] - 'a']--;  // Decrement frequency for each character in str2
    }

    // Check if all frequencies are zero, meaning both strings have the same characters
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)  // If any frequency is non-zero, they are not anagrams
            return false;
    }

    return true;  
        // if(s.length()!=t.length()){
        //     return false;
        // }
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // for(int i=0;i<s.length();i++){
        //     if(s[i]!=t[i]){
        //         return false;
        //     }
        // }
        // return true;
    }
};