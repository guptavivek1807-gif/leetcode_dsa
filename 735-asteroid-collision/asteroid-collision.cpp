class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        bool destroyed = false;
        for(int i : asteroids){
            if(i > 0){
                v.push_back(i);
            }
            else{
                while(!v.empty() && v.back() > 0 && v.back() <= abs(i)){
                    if(v.back() == abs(i)){
                        v.pop_back();
                        destroyed = true;
                        break;
                    }
                    v.pop_back();
                }
                if((v.empty() || v.back() < 0) && !destroyed){
                    v.push_back(i);
                }

                destroyed = false;
            }
        }
        return v;

    }
};