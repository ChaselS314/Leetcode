class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.empty()) return false;
        if(word.size() == 1) return true;
        if(islower(word[0])){
            // all letters must be not capitals
            for(auto it : word){
                if(isupper(it))
                    return false;
            }
            return true;
        }
        else{
            if(islower(word[1])){
                // all folowing letters must be not capitals
                size_t cnt = 0;
                for(auto it : word){
                    if(cnt++ < 2) continue;
                    if(isupper(it))
                        return false;
                }
                return true;
            }
            else{
                // all folowing letters must be capitals
                size_t cnt = 0;
                for(auto it : word){
                    if(cnt++ < 2) continue;
                    if(islower(it))
                        return false;
                }
                return true;
            }
        }
    }
};

// this post is better than mine
class Solution {
public:
    bool detectCapitalUse(string word) {
       // AAA
        auto isUpper =[](const string &word) {
          for (auto x : word) {
              if (x >= 'a')
                  return false;
          }
          return true;
        };
        // Aaa or aaa
        auto isLower = [](const string &word) {
          for (int i = 1; i < word.size(); ++i) {
              if (word[i] < 'a')
                  return false;
          }
          return true;
        };
        return isUpper(word) || isLower(word);
    };
};
