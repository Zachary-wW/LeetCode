#include <bits/stdc++.h>
using namespace std;


// 

class LC131 {
public:

    bool isPalindrome(const string& s, int start, int end){
        for(int i = start, j = end; i < j; ++i, --j){
            if(s[i] != s[j]) return false;
        }
        return true;
    }

    void backTracking(const string& s, int index){
        if(index >= s.length()){
            ans.emplace_back(path);
            return;
        }

        for(int i = index; i < s.length(); ++i){
            if(isPalindrome(s, index, i)){// 判断是否为回文
                string str = s.substr(index, i - index + 1);
                path.emplace_back(str);
            } else{
                continue;
            } 
            backTracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return ans;
    }

private:
    vector<vector<string>> ans;
    vector<string> path;
    
};