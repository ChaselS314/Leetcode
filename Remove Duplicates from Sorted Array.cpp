class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        if(nums.size() < 2) return nums.size();
        while(j < nums.size()){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};

// 使用STL
// unique() in <algorithm>
// distance() in <iterator>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
};