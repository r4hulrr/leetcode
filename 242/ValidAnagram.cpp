class Solution {
public:
    bool isAnagram(string s, string t){
        if (s.length() != t.length()) return false;
        std::unordered_map<char,int> map_s;
        std::unordered_map<char,int> map_tt;
        for (int i = 0 ; i < s.length() ; i++){
            map_s[s[i]]++;
            map_tt[t[i]]++;
        }
        return map_s == map_tt;
    }
};