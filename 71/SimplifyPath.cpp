class Solution {
public:
    string simplifyPath(string path) {
        std::istringstream ss(path);
        std::vector<std::string> paths;
        std::string pat;
        while(std::getline(ss, pat, '/')){
            if (pat == "." || pat.empty()) continue;
            if (pat == ".."){
                if (!paths.empty()) paths.pop_back();
            }else{
                paths.push_back(pat);
            }
        }
        std::string result;
        for (const auto& p : paths){
            result += "/" + p;
        }

        return (result.empty()? "/" : result);
    }
};