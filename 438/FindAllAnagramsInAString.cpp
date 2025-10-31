class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // map to store number of characters
        unordered_map<char, int> need, window;
        for(char c: p){
            need[c]++;
        }
        // pointers for left and right of sliding window
        int left = 0, right = 0;
        // checks if valid
        int valid = 0;
        // vector to return
        vector<int> answer;
        while(right < s.size()){
            char c = s[right];
            right ++;
            if (need.count(c)){
                window[c]++;
                if (need[c] == window[c]){
                    valid++;
                }
            }
            while((right - left) >= p.size()){
                if (valid == need.size()){
                    answer.push_back(left);
                }
                char d = s[left];
                // shrink window
                left++;
                if (need.count(d)){
                    if (need[d] == window[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return answer;
    }
};