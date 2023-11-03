#include <bits/stdc++.h>
using namespace std;


// 这道题难点在于如何想到使用回溯进行处理

class LC131 {
public:

    bool isPalindrome(const string& s, int start, int end){
        for(int i = start, j = end; i < j; ++i, --j){
            if(s[i] != s[j]) return false;
        }
        return true;
    }

    void backTracking(const string& s, int index){
        if(index >= s.length()){ // index其实就是切割线
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

// 这道题多了一个约束条件 点的数量

class LC93 {
public:
    bool isValid(const string& s, int begin, int end){
        // 非法输入
        if(begin > end) return false;
        // 前导0
        if(s[begin] == '0' && begin != end) return false;
        // 非法输入 & 总数不能大于255
        int sum = 0;
        for(int i = begin; i <= end; ++i){
            // 检查是否非法
            if(s[i] > '9' || s[i] < '0') return false;
            // 计算和
            sum = sum * 10 + s[i] - '0';
            if(sum > 255) return false;
        }
        return true;
    }

    void backTracking(string& s, int index, int pointNum){
        if(pointNum == 3){ // 终止条件 点的数量到3的时候判断后面的字符串是否有效
            if(isValid(s, index, s.length() - 1)){
                ans.emplace_back(s);
                return;
            }
        }

        for(int i = index; i < s.length(); ++i){
            if(isValid(s, index, i)){ // 判断有效才能加入点
                s.insert(s.begin() + i + 1, '.');
                ++pointNum;
                backTracking(s, i + 2, pointNum);
                s.erase(s.begin() + i + 1);
                --pointNum;
            }else break; // 例如 @21231213123 第一个非法 后面就不用判断了
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backTracking(s, 0, 0);
        return ans;
    }
private:
    vector<string> ans;
};

//