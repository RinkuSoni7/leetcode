class Solution {
public:
    static int countBits(int n) {
        return __builtin_popcount(n);   // GCC/Clang built-in
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            if (countA == countB)
                return a < b;   // sort by value if bit counts equal
            
            return countA < countB;   // sort by bit count
        });
        
        return arr;
    }
};