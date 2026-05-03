class Solution {
public:

    bool ispossible(vector<int>& piles, int h, int mid){
        long long actualhour = 0;

        for(int x : piles){
            actualhour += (x + mid - 1) / mid;

            if(actualhour > h) return false;  // 🔥 early stop
        }

        return actualhour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(ispossible(piles, h, mid)){
                ans = mid;
                e = mid - 1;   // minimize speed
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};