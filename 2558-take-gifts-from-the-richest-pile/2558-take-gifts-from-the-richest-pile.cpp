class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i : gifts){
            pq.push(i);
        }

        while(k--){
            long long a=pq.top();
            pq.pop();

            long long b=sqrt(a);

            pq.push(b);
        }

        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }

        return sum;
        
    }
};