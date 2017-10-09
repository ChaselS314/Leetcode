// First solution : sort and traversal
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(auto it = nums.begin() + 1; it != nums.end(); it++){
            if(*it == *(it-1)) return *it;
        }
    }
};
// Second solution : quick and slow pointer(better)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[nums[0]], slow = nums[0];
        while(fast != slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};
