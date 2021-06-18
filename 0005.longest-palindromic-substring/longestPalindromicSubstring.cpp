struct IndexGroup {
    int i = -1;
    int j = -1;
};
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }
        vector<vector<bool>> dp (s.size(), vector<bool>(s.size(), 0));
        for (int i = 0 ; i < s.size(); ++i){
            dp[i][i] = true;
            saveRes(i, i);
        }
        for (int L = 2; L <= s.size(); ++L){
            for (int i = 0 ; i < s.size(); ++i){
                int j = i + L -1;
                if (j >= s.size()){
                    continue;
                }
                if (i < j && L == 2 && s[i] == s[j]){
                    dp[i][j] = true;
                    saveRes(i, j);
                } else if (i < j && s[i] == s[j] && dp[i+1][j-1] == true) {
                    dp[i][j] = true;
                    saveRes(i, j);
                }
                else {}
            }
        }
        
        return s.substr(indexGroup_.i, maxLen_);
    }
    void saveRes(const int &i , const int &j){
        if (maxLen_ < j - i + 1) {
            maxLen_ = j-i+1;
            indexGroup_.i = i;
            indexGroup_.j = j;
        }
    }

private:
    IndexGroup indexGroup_;
    int maxLen_ = -1;
};