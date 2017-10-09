class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for(auto it = nums.begin() + 1; it != nums.end(); it++){
            if(*it == *(it-1)) return *it;
        }
    }
};
