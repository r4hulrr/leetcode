class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // hash map to keep track of window
        unordered_map<char, int> window;
        // pointers for left and right of sliding window
        int left = 0, right = 0;
        // to keep track of longest substring
        int len = 0;
        while(right < s.size()){
            char c = s[right];
            right++;
            window[c]++;
            while(window[c] > 1){
                // shrink the window
                char d = s[left];
                left++;
                window[d]--;
            }
            len = max(len, right - left);
        }
        return len;
    }
};