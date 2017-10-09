class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        bool onlyonce = true;
        int i = 0, j = 1;
        for(; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
                onlyonce = true;
            }
            else if(onlyonce){
                nums[++i] = nums[j];
                onlyonce = false;
            }
            /* or:
            if(nums[i] != nums[j] || onlyonce){
                nums[++i] = nums[j];
                onlyonce = nums[i-1] != nums[j] ? true : false;
            }
            */
        }
        
        return i+1;
    }
};

// 题目要求最多允许2个重复，所以只要保证当前元素与上上一个元素不相等即可满足条件
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int index = 2;
        for (int i = 2; i < nums.size(); i++){
            if (nums[i] != nums[index - 2])
            nums[index++] = nums[i];
        }
        return index;
    }
};
