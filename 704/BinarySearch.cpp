class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while ( left <= right){
            int mid = left + (right - left)/2;
            // if mid is greater than target modify the right side
            // [left, mid - 1]
            if (nums[mid] > target){
                right = mid - 1;
            }else if (nums[mid] < target){
                // [mid + 1, right]
                left = mid + 1;
            }else if (nums[mid] == target){
                return mid;
            }
        }
        return -1;
    }
};