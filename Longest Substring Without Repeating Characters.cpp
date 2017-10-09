class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> ishere;
        size_t begin = 0, end = 0, len = 0, maxlen = 0;
        while(true){
            if(end == s.size()) break;
            if(ishere.count(s[end]) == 0){
                ishere.insert(s[end]);
                ++end;
                ++len;
                maxlen = len > maxlen ? len : maxlen;
            }
            else{
                ishere.erase(s[begin]);
                ++begin;
                --len;
            }
        }
        return maxlen;
    }
};
// 别人的方法，比我的方法好的地方在于，根据遍历顺序给dict数组s赋值，start代表了每个字串的起始位置，当出现重复字符时，可以直接定位到下一个有效的字串
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
