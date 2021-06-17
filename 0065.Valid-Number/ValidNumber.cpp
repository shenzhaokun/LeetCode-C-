class Solution {
public:
    bool isNumber(string s) {
        for (int i = 0 ; i < s.size(); ++i ){
            if ( i == 0 && (s[i] == '+' || s[i] == '-')) {
                continue;
            } else if (s[i] == '.'){
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                continue;
            } else if (s[i] == 'e' || s[i] == 'E')  {
                return (isInt(s.substr(0, i)) || isDecimals(s.substr(0, i))) && checkE(s.substr(i));
            } else {
                return false;
            }
        }
        return isInt(s) || isDecimals(s);
    }

    bool checkE(string s) {
        return isInt(s.substr(1));
    }

    bool isInt(string s) {
        for (char ch : s) {
            if (ch == '+' || ch == '-'){
                return isUnsignedInt(s.substr(1));
            }
            else {
                return isUnsignedInt(s.substr(0));
            }
        }
        return false;
    }

    bool isUnsignedInt(string s) {
        if (s.empty()) {
            return false;
        }
        for (char ch : s) {
            if (ch < '0' || ch > '9') {
                return false;
            }
        }
        return true;
    }

    bool isDecimals(string s){
        if (s.size() <= 1) {
            return false;
        }
        bool flag = false;
        for (int i = 0 ; i < s.size(); ++i) {
            if ( i == 0 && (s[i] == '+' || s[i] == '-')) {
                flag = true;
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                continue;
            } else if (s[i] == '.') {
                if (flag){
                    if (s.size() <= 2){
                        return false;
                    }
                    return (s.substr(i+1).empty() || isUnsignedInt(s.substr(i+1))) && (s.substr(1, i-1).empty() || isInt(s.substr(1, i-1)));
                } else {
                    return (s.substr(i+1).empty() || isUnsignedInt(s.substr(i+1))) && (s.substr(0, i).empty() || isInt(s.substr(0, i)));
                }     
            }
            else {
                return false;
            }
        }
        return false;
    } 
};
