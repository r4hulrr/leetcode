class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> result = nextGreaterElement(nums2);
        // create a hash map to store result of each index
        std::unordered_map<int,int> map;
        for(int i = 0; i < result.size(); i++){
            map[nums2[i]] = result[i];
        }
        // use this map to get result
        std::vector<int> final(nums1.size());
        for (int i = 0; i < nums1.size(); i++){
            final[i] = map[nums1[i]];
        }
        return final;
    }

    vector<int> nextGreaterElement(vector<int>& nums){
        std::stack<int> s;
        std::vector<int> result(nums.size());
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            while(!s.empty() && nums[i] >= s.top()){
                s.pop();
            }
            result[i] = s.empty()? -1 : s.top();
            s.push(nums[i]);
        }
        return result;
    }
};