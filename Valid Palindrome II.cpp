class Solution {
public:
    bool isPalindrom(string s){
        if(s.empty()) return true;
        int begin = 0, end = s.size() -1;
        while(begin < end){
            if(s[begin] != s[end])
                return false;
            ++begin;
            --end;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int begin = 0, end = s.size() -1;
        while(begin < end){
            if(s[begin] != s[end])
                return isPalindrom(s.substr(begin, end-begin)) || isPalindrom(s.substr(begin+1, end-begin));
            ++begin;
            --end;
        }
        return true;
    }
};
