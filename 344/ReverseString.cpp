class Solution {
public:
    void reverseString(vector<char>& s) {
        // two pointers one at the end one at beginning
        int left = 0, right = s.size() - 1;
        while(left < right){
            char c = s[left];
            char d = s[right];
            s[left] = d;
            s[right] = c;
            left++;
            right--;
        }
    }
};