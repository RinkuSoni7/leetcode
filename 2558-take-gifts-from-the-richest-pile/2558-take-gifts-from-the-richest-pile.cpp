class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long >pq;
        for(int i=0; i<gifts.size(); i++){
            pq.push(gifts[i]);
        }

        while(k--){
            long long first=pq.top();
            pq.pop();
            long long num=sqrt(first);
            pq.push(num);
        }
        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }


        return sum;
    }
};