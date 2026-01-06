class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // make a 26 string char which keeps track of all chars
        // this should be the key 
        // the value should be a vector which stores a  
        // vector of strings
        std::unordered_map<std::string, std::vector<string>> map;
        // start by traversing through the vector and forming 
        // a char string for each string
        // then storing that string as the key with the value being the 
        // string that was passed to the function
        for(string s : strs){
            map[stringOf(s)].push_back(s);
        }
        // now we only want the values to be stored in a vector not keys
        std::vector<std::vector<string>> result;

        for(auto& keys : map){
            result.push_back(std::vector<string>(keys.second.begin(), keys.second.end()));
        }
        return result;
    }
    std::string stringOf(std::string str){
        std::string s(26,0);
        // find index of each char in string
        for(char c : str){
            int index = c - 'a';
            s[index]++;
        }
        return s;
    }
};
