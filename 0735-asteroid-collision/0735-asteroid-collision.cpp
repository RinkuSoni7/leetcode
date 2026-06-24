class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>s;
        for(auto &a : asteroids){
            while(!s.empty() && s.top() >0 && a<0){
                int sum =a+s.top();
                if(sum>0){
                    a=0;
                }
                else if(sum <0){
                    s.pop();
                }
                else{
                    s.pop();
                    a=0;
                }
            }
            if(a!=0){
                s.push(a);
            }
        }
        vector<int>ans(s.size());
        int i=s.size()-1;

        while(!s.empty()){
            ans[i]=s.top();
            i--;
            s.pop();
        }
        return ans;
    }
};