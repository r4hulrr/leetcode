class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = removeElement(nums);
        for(; p < nums.size() ; p++){
            nums[p] = 0;
        }
    }

    int removeElement(vector<int>& nums){
        int slow = 0, fast = 0;
        while(fast < nums.size()){
            if (nums[fast] != 0){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};