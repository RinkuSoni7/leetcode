
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for (int i = s.size() - 1; i > 0; i--) {
            if ((s[i] - '0' + carry) % 2 == 1) {
                steps += 2;  // add 1 and divide
                carry = 1;
            } else {
                steps += 1;  // divide only
            }
        }

        return steps + carry;
    }
};