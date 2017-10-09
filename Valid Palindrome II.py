class Solution(object):
    def isPalindrome(self, s):
        if len(s) == 0:
            return True
        begin, end = 0, len(s)-1
        while begin < end:
            if s[begin] != s[end]:
                return False
            begin += 1
            end -= 1
        return True
    
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # s is not null string
        begin, end = 0, len(s)-1
        while begin < end:
            if s[begin] != s[end]:
                return self.isPalindrome(s[begin+1 :  end + 1]) or self.isPalindrome(s[begin : end])
            begin += 1
            end -= 1
        return True
