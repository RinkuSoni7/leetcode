class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0; i<stones.size(); i++){
            pq.push(stones[i]);
        }
        
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(first!=second){
            int num=first-second;
            pq.push(num);
            }
            if(first==second){
                pq.push(0);
            }
        }
        // return pq.empty() ? 0 : pq.top();
        return pq.top();
    }
};