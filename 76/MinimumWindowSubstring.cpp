class Solution {
public:
    string minWindow(string s, string t) {
        // unordered map to keep track of characters in string
        unordered_map<char, int> need, window;
        for(char c : t){
            need[c]++;
        }
        // keep track of left and right sliding pointers
        int left = 0, right = 0;
        // keep track of if valid and length of window
        int valid = 0, len = INT_MAX;
        int start = 0;
        while(right < s.size()){
            // get char from the string
            char d = s[right];
            // increment the window
            right++;
            // check if this character is part of want, if so record in a window
            if (need.count(d)){
                window[d]++;
                // check if the number of times that char appears in window and need are the same
                if (window[d] == need[d]){
                    valid++;
                }
            }
            while (valid == need.size()){
                // record starting position if less than prev max lenght
                if ( (right - left) < len){
                    len = right - left;
                    start = left;
                }
                char e = s[left];
                // shrink the window
                left++;
                // check if valid after removing char
                if (need.count(e)){
                    if (window[e] == need[e])
                        valid--;
                    window[e]--;
                }
            }
        }
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};