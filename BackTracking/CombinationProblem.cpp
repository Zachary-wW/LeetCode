#include <bits/stdc++.h>
using namespace std;

// 组合问题1 LeetCode 77
// Solution
class Solution {
public:
    void backtracking(int n, int k, int startInedx){
        if(k == vec.size()){
            ans.emplace_back(vec);
            return;
        }

        // for(int i = startInedx; i <= n; ++i){
        //     vec.emplace_back(i);
        //     backtracking(n, k, i+1);
        //     vec.pop_back();
        // }

        // 当前组合个数vec.size() 总共k 如果剩下的元素数量小于要求的个数就没必要遍历了
        // n - i >= k - vec.size() 则 i <= n - k + vec.size() + 1
        for(int i = startInedx; i <= n - k + vec.size() + 1; ++i){
            vec.emplace_back(i);
            backtracking(n, k, i+1);
            vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> vec;
};

// 时间复杂度: O(n * 2^n)  空间复杂度: O(n)


// 组合问题2 LeetCode216
class Solution {
public:

    void backTracking(int target, int sum, int k, int startIndex){
        if(k == vec.size()){
            if(sum == target){
                ans.emplace_back(vec);
            }
            return;
        }

        // for(int i = startIndex; i <= 9; ++i){
        //     vec.emplace_back(i);
        //     sum += i;
        //     backTracking(target, sum, k, i + 1);
        //     sum -= i;
        //     vec.pop_back();
        // }

        for(int i = startIndex; i <= 9 - k + vec.size() + 1; ++i){
            vec.emplace_back(i);
            sum += i;

            if(sum > target){
                vec.pop_back();
                sum -= i;
                return;
            }

            backTracking(target, sum, k, i + 1);
            sum -= i;
            vec.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(n, 0, k, 1);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> vec;
};

// 时间复杂度: O(n * 2^n)  空间复杂度: O(n)

// 组合问题3 LeetCode 17

class Solution {
public:

    void backTracking(const string& str, int index){
        if(str.length() == index){
            ans.emplace_back(s);
            return;
        }

        string sstr = stringMap[str[index] - '0'];
        for(int i = 0; i < sstr.length(); ++i){
            s.push_back(sstr[i]);
            backTracking(str, index + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        backTracking(digits, 0);
        return ans;
    }

private:
    vector<string> ans;
    string s;
    const string stringMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
};

// 时间复杂度: O(3^m * 4^n)，其中 m 是对应四个字母的数字个数，n 是对应三个字母的数字个数
// 空间复杂度: O(3^m * 4^n)

// LeetCode 39
// version 1
class Solution {
public:

    void backTracking(vector<int>& candidates, int target, int sum, int index){
        if(sum > target) return;
        if(target == sum){
            ans.emplace_back(vec);
            return;
        }

        for(int i = index; i < candidates.size(); ++i){
            sum += candidates[i];
            vec.emplace_back(candidates[i]);
            backTracking(candidates, target, sum, i);
            sum -= candidates[i];
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        backTracking(candidates, target, 0, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> vec;
};

// version 2
class Solution {
public:

    void backTracking(vector<int>& candidates, int target, int sum, int index){
        //if(sum > target) return;
        if(target == sum){
            ans.emplace_back(vec);
            return;
        }

        for(int i = index; i < candidates.size() && sum + candidates[i] <= target; ++i){
            sum += candidates[i];
            vec.emplace_back(candidates[i]);
            backTracking(candidates, target, sum, i);
            sum -= candidates[i];
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> vec;
};

// LeetCode 39

class Solution {
public:

    void backTracing(vector<int>& candidates, int target, int sum, int index, vector<bool>& flag){
        if(sum == target){
            ans.emplace_back(vec);
            return;
        }

        for(int i = index; i < candidates.size() && sum + candidates[i] <= target; ++i){
            if(i > 0 && candidates[i - 1] == candidates[i] && flag[i - 1] == false){
                continue;
            }
            sum += candidates[i];
            vec.emplace_back(candidates[i]);
            flag[i] = true;
            backTracing(candidates, target, sum, i + 1, flag);
            sum -= candidates[i];
            vec.pop_back();
            flag[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> flag(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backTracing(candidates, target, 0, 0, flag);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> vec;
};

// 时间复杂度: O(n * 2^n) 空间复杂度: O(n)


class Solution {
public:
    // left是左括号 right是右括号
    void backTracking(int n, int left, int right){
        // 终止条件 当string长度为给定值n的两倍时，说明已经回溯完了
        if(path.size() == 2 * n){
            ans.emplace_back(path);
        }
        // 一般的回溯这里是一个for循环
        // 其实这里只是把for循环给拆开了，因为每个分支的条件不同
        if(left < n){// 加入左括号的条件
            path += '(';
            backTracking(n, left + 1, right);
            path.pop_back();
        }
        if(right < left){// 加入右括号的条件
            path += ')';
            backTracking(n, left, right + 1);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backTracking(n, 0, 0);
        return ans;
    }
private:
    vector<string> ans;
    string path;
};