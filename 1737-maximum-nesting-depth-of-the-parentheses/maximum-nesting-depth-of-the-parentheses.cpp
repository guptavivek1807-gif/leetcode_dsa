class Solution {
public:
    int maxDepth(string s) {
        int openbracket=0;
        int result=0;
        for(char &ch:s){
            if(ch=='('){
                openbracket++;
            } else if(ch==')'){
                openbracket--;
            }
            result=max(result,openbracket);
        }
        return result;
    }
};