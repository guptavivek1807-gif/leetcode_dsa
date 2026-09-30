class Solution {
public:
char tolowercase(char ch){
    if(ch>='a' && ch<='z')
    return ch;
    else {
        char temp = ch-'A'+'a';
        return temp;
    }
}
    bool isPalindrome(string s) {
        int st=0;
        int e=s.size()-1;
        while(st<=e){
            if (!isalnum(s[st])) {
        st++;
        continue;
       
     
    }
    // 2. Skip non-alphanumeric characters from the end
     if (!isalnum(s[e])) {
        e--;
        continue;
       
        
    }
            if(tolowercase(s[st])!=tolowercase(s[e])){
                return 0;
            } else {
                st++;
                e--;
            }
        } return 1;
        
    }
};