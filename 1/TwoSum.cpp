class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hash map to store nums and its index
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size() ; i++){
            int required = target - nums[i];
            if(hash.count(required)){
                return {i, hash[required]};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};