class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // stores number of characters in a hash map
        unordered_map<char, int> need, window;
        for (char c : s1){
            need[c]++;
        }
        // pointers for left and right of sliding window
        int left = 0, right = 0;
        // checks if it contains all characters required
        int valid = 0;
        while(right < s2.size()){
            char c = s2[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if (need[c] == window[c]){
                    valid++;
                }
            }
            while((right - left) >= s1.size()){
                if (valid == need.size()){
                    return true;
                }
                // shrink window
                char d = s2[left];
                left++;
                if (need.count(d)){
                    if (need[d] == window[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};